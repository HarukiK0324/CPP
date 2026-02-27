#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <climits>
#include <stdexcept>
#include <vector>

class Span {
    public:
        void addNumber(int number);
        template <typename iter> void addNumbers(iter begin, iter end) {
            if(_numbers.size() + std::distance(begin, end) > _N)
                throw std::runtime_error("Span is full");
            _numbers.insert(_numbers.end(), begin, end);
        }
        unsigned int shortestSpan();
        unsigned int longestSpan();

        Span();
        Span(unsigned int N);
        Span(const Span& src);
        Span& operator=(const Span& src);
        ~Span();
    private:
        unsigned int _N;
        std::vector<int> _numbers;
};

#endif
