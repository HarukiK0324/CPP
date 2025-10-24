#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->_type = "Dog";
    this->_brain = new Brain();
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
        this->_type = src._type;
        this->_brain = new Brain(*(src._brain));
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->_brain;
}

std::string Dog::getType() const
{
    return this->_type;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;
}

Brain * Dog::getBrain() const
{
    return this->_brain;
}