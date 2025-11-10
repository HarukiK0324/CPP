#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &src) 
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = src;
}

Dog &Dog::operator=(const Dog &src)
{
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &src)
    {
        this->type = src.type;
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

std::string Dog::getType() const
{
    return this->type;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;
}
