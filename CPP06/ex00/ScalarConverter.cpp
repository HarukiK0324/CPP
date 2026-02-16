#include "ScalarConverter.hpp"

static bool isChar(const std::string& literal) {
    return literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0]));
}

static void displayOutputs(double v) {
    std::cout << "char: ";
    if (v != v || v < std::numeric_limits<char>::min() || v > std::numeric_limits<char>::max())
        std::cout << "impossible\n";
    else {
        char c = static_cast<char>(v);
        if (std::isprint(static_cast<unsigned char>(c)))
            std::cout << "'" << c << "'\n";
        else
            std::cout << "Non displayable\n";
    }
    std::cout << "int: ";
    if (v != v || v <= static_cast<double>(INT_MIN) - 1.0 || v >= static_cast<double>(INT_MAX) + 1.0)
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(v) << "\n";

    std::cout << "float: ";
    if (v != v)
        std::cout << "nanf\n";
    else {
        float f = static_cast<float>(v);
        if (f == std::numeric_limits<float>::infinity())
            std::cout << "+inff\n";
        else if (f == -std::numeric_limits<float>::infinity())
            std::cout << "-inff\n";
        else {
            std::cout << f;
            if (f == std::floor(f))
                std::cout << ".0";
            std::cout << "f\n";
        }
    }
    std::cout << "double: ";
    if (v != v)
        std::cout << "nan\n";
    else {
        double d = static_cast<double>(v);
        if (d == std::numeric_limits<double>::infinity())
            std::cout << "+inf\n";
        else if (d == -std::numeric_limits<double>::infinity())
            std::cout << "-inf\n";
        else {
            std::cout << d;
            if (d == std::floor(d))
                std::cout << ".0";
            std::cout << "\n";
        }
    }
}

void ScalarConverter::convert(const std::string& literal) {
    if (literal.empty()) {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
        return;
    }

    if (literal == "nan" || literal == "nanf" ||
        literal == "+inf" || literal == "+inff" ||
        literal == "-inf" || literal == "-inff") {
        double d = 0.0;
        if (literal == "nan" || literal == "nanf") 
            d = std::numeric_limits<double>::quiet_NaN();
        else if (literal[0] == '+')
            d = std::numeric_limits<double>::infinity();
        else 
            d = -std::numeric_limits<double>::infinity();
        displayOutputs(d);
        return;
    }

    if (isChar(literal)) {
        displayOutputs(static_cast<double>(literal[0]));
        return;
    }

    char* endPtr = NULL;
    
    if (literal.find('.') == std::string::npos && literal.find('e') == std::string::npos && 
        literal.find('E') == std::string::npos && literal[literal.length() - 1] != 'f') {
        errno = 0;
        long l = std::strtol(literal.c_str(), &endPtr, 10);
        if (*endPtr == '\0' && errno != ERANGE && l >= std::numeric_limits<int>::min() && l <= std::numeric_limits<int>::max()) {
            displayOutputs(static_cast<double>(static_cast<int>(l)));
            return;
        }
    }

    if (literal[literal.length() - 1] == 'f') {
        errno = 0;
        double d = std::strtod(literal.c_str(), &endPtr);
        if (*endPtr == 'f' && *(endPtr + 1) == '\0' && errno != ERANGE) {
            displayOutputs(static_cast<double>(static_cast<float>(d)));
            return;
        }
    }

    errno = 0;
    double d = std::strtod(literal.c_str(), &endPtr);
    if (*endPtr == '\0' && errno != ERANGE) {
        displayOutputs(d);
        return;
    }
    std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& src) { (void)src; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src) { (void)src; return *this; }
ScalarConverter::~ScalarConverter() {}
