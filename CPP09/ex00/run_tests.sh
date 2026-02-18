#!/bin/bash

PROGRAM="./btc"  # Adjust to your binary name
PASS=0
FAIL=0

run_test() {
    local description="$1"
    local input_file="$2"
    local expected_stdout="$3"
    local expected_stderr="$4"

    stdout=$($PROGRAM "$input_file" 2>/dev/null)
    stderr=$($PROGRAM "$input_file" 2>&1 1>/dev/null)

    local failed=0

    if [ -n "$expected_stdout" ]; then
        if [ "$stdout" != "$expected_stdout" ]; then
            echo "❌ FAIL: $description (stdout mismatch)"
            echo "  Expected stdout:"
            echo "$expected_stdout" | sed 's/^/    /'
            echo "  Got stdout:"
            echo "$stdout" | sed 's/^/    /'
            failed=1
        fi
    fi

    if [ -n "$expected_stderr" ]; then
        if [ "$stderr" != "$expected_stderr" ]; then
            echo "❌ FAIL: $description (stderr mismatch)"
            echo "  Expected stderr:"
            echo "$expected_stderr" | sed 's/^/    /'
            echo "  Got stderr:"
            echo "$stderr" | sed 's/^/    /'
            failed=1
        fi
    fi

    if [ $failed -eq 0 ]; then
        echo "✅ PASS: $description"
        PASS=$((PASS + 1))
    else
        FAIL=$((FAIL + 1))
    fi
}

# ──────────────────────────────────────────────
# Test 0: No arguments
# ──────────────────────────────────────────────
stderr=$(./btc 2>&1)
if echo "$stderr" | grep -q "Error"; then
    echo "✅ PASS: No arguments gives error"
    PASS=$((PASS + 1))
else
    echo "❌ FAIL: No arguments should give error"
    FAIL=$((FAIL + 1))
fi

# ──────────────────────────────────────────────
# Test 1: Nonexistent file
# ──────────────────────────────────────────────
stderr=$(./btc nonexistent_file.txt 2>&1)
if echo "$stderr" | grep -q "Error"; then
    echo "✅ PASS: Nonexistent file gives error"
    PASS=$((PASS + 1))
else
    echo "❌ FAIL: Nonexistent file should give error"
    FAIL=$((FAIL + 1))
fi

# ──────────────────────────────────────────────
# Test 2: Basic valid input
# ──────────────────────────────────────────────
# 2011-01-03: closest date <= is 2011-01-01 with rate 0.3
# 2011-01-09: closest date <= is 2011-01-07 with rate 0.32
# 2012-01-11: exact match with rate 7.1
run_test "Basic valid input" "test_basic.txt" \
"2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
2012-01-11 => 1 = 7.1
2012-01-11 => 2 = 14.2" \
""

# ──────────────────────────────────────────────
# Test 3: Error cases
# ──────────────────────────────────────────────
run_test "Error cases - all lines should produce errors" "test_errors.txt" \
"" \
""
# For error cases, just verify no stdout and all stderr
stdout=$($PROGRAM "test_errors.txt" 2>/dev/null)
if [ -z "$stdout" ]; then
    echo "✅ PASS: Error file produces no valid output"
    PASS=$((PASS + 1))
else
    echo "❌ FAIL: Error file should produce no valid output, got:"
    echo "$stdout" | sed 's/^/    /'
    FAIL=$((FAIL + 1))
fi

stderr_count=$($PROGRAM "test_errors.txt" 2>&1 1>/dev/null | wc -l)
if [ "$stderr_count" -ge 14 ]; then
    echo "✅ PASS: Error file produces at least 14 error lines (got $stderr_count)"
    PASS=$((PASS + 1))
else
    echo "❌ FAIL: Error file should produce at least 14 error lines, got $stderr_count"
    echo "  Errors were:"
    $PROGRAM "test_errors.txt" 2>&1 1>/dev/null | sed 's/^/    /'
    FAIL=$((FAIL + 1))
fi

# ──────────────────────────────────────────────
# Test 4: Edge cases
# ──────────────────────────────────────────────
# 2009-01-02: exact match, rate 0 => result 0
# 2009-01-03: no exact match, closest <= is 2009-01-02 with rate 0
# 2022-03-29: exact match (last entry), rate 47115.93
# 2022-03-30: no exact match, closest <= is 2022-03-29 with rate 47115.93
# 2011-02-28: closest <= is 2011-02-27 with rate 0.96
# 2012-02-29: closest <= is 2012-02-28 with rate 4.98
# value 0 => result 0
# value 1000 => max boundary
run_test "Edge cases" "test_edge_cases.txt" \
"2009-01-02 => 1 = 0
2009-01-03 => 1 = 0
2022-03-29 => 1 = 47115.9
2022-03-30 => 1 = 47115.9
2011-02-28 => 1 = 0.96
2012-02-29 => 1 = 4.98
2011-01-03 => 0 = 0
2011-01-03 => 1000 = 300" \
""

# ──────────────────────────────────────────────
# Test 5: Empty file (only header)
# ──────────────────────────────────────────────
echo "date | value" > test_empty.txt
stdout=$($PROGRAM "test_empty.txt" 2>/dev/null)
if [ -z "$stdout" ]; then
    echo "✅ PASS: Empty file (header only) produces no output"
    PASS=$((PASS + 1))
else
    echo "❌ FAIL: Empty file should produce no output"
    FAIL=$((FAIL + 1))
fi
rm -f test_empty.txt

# ──────────────────────────────────────────────
# Test 6: Date before earliest CSV entry
# ─────────���────────────────────────────────────
echo "date | value" > test_too_early.txt
echo "2009-01-01 | 1" >> test_too_early.txt
stderr=$($PROGRAM "test_too_early.txt" 2>&1 1>/dev/null)
if echo "$stderr" | grep -qi "error"; then
    echo "✅ PASS: Date before earliest CSV entry gives error"
    PASS=$((PASS + 1))
else
    echo "❌ FAIL: Date before earliest CSV entry should give error"
    FAIL=$((FAIL + 1))
fi
rm -f test_too_early.txt

# ──────────────────────────────────────────────
# Summary
# ──────────────────────────────────────────────
echo ""
echo "================================"
echo "Results: $PASS passed, $FAIL failed"
echo "================================"