#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <iostream>

template <typename T> class Array {
    private:
        T* array;
        std::size_t size;
    public:
        Array() : size(0){
            std::cout << "Default constructor called" << std::endl;
            array = new T[0];
        }

        Array(unsigned int n) : size(n) {
            std::cout << "Parameterized constructor called" << std::endl;
            array = new T[n];
        }

        Array(const Array& src) : size(src.size) {
            std::cout << "Copy constructor called" << std::endl;
            *this = src;
        }

        Array& operator=(const Array& src) {
            std::cout << "Assignment operator called" << std::endl;
            if (this != &src) {
                delete[] array;
                size = src.size;
                array = new T[size];
                for (std::size_t i = 0; i < size; i++) {
                    array[i] = src.array[i];
                }
            }
            return *this;
        }

        ~Array() {
            std::cout << "Destructor called" << std::endl;
            delete[] array;
        }

        T& operator[](std::size_t index) {
            if (index >= size || this->array == nullptr) {
                throw IndexOutOfBoundsException();
            }
            return array[index];
        }

        class IndexOutOfBoundsException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Index out of bounds";
                }
        };

        std::size_t getSize() const {
            return size;
        }
};

#endif
