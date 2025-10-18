#include "Animal.hpp"

Animal::Animal() : _type("")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &src )
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
}

Animal &Animal::operator=(const Animal &src)
{
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &src)
    {
        this->_type = src._type;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return this->_type;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}
