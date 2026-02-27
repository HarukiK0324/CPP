#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <iostream>
#include <exception>

template <typename T> class Array {
    private:
        T* _array;
        std::size_t _size;
    public:
        Array() : _size(0){
            _array = new T[0];
        }

        Array(unsigned int n) : _size(n) {
            _array = new T[_size]();
        }

        Array(const Array& src) : _array(NULL), _size(src._size) {
            *this = src;
        }

        Array& operator=(const Array& src) {
            if (this != &src) {
                delete[] _array;
                _size = src._size;
                _array = new T[_size];
                for (std::size_t i = 0; i < _size; i++) {
                    _array[i] = src._array[i];
                }
            }
            return *this;
        }

        ~Array() {
            delete[] _array;
        }

        T& operator[](std::size_t index) {
            if (index >= _size || this->_array == NULL) {
                throw IndexOutOfBoundsException();
            }
            return _array[index];
        }

        const T& operator[](std::size_t index) const {
            if (index >= _size || this->_array == NULL) {
                throw IndexOutOfBoundsException();
            }
            return _array[index];
        }
        
        class IndexOutOfBoundsException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Index out of bounds";
                }
        };

        std::size_t size() const {
            return _size;
        }
};

#endif
