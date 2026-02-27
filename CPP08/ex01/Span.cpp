#include "Span.hpp"

void Span::addNumber(int number) {
    if(_numbers.size() >= _N)
        throw std::runtime_error("Span is full");
    _numbers.push_back(number);
}

unsigned int Span::shortestSpan() {
    if(_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers");
    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());
    unsigned int minSpan = UINT_MAX;
    for(size_t i = 1; i < sorted.size(); ++i) {
        unsigned int span = static_cast<unsigned int>(sorted[i]) - static_cast<unsigned int>(sorted[i - 1]);
        if(span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

unsigned int Span::longestSpan() {
    if(_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers");
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return static_cast<unsigned int>(max) - static_cast<unsigned int>(min);
}

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span& other) : _N(other._N), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _N = other._N;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}
