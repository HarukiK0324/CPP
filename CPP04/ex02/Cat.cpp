#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constructor called" << std::endl;
    this->_brain = new Brain();
    this->_type = "Cat";
}

Cat::Cat(const Cat &src)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = src;
}

Cat &Cat::operator=(const Cat &src)
{
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &src)
    {
        this->_type = src._type;
        this->_brain = new Brain(*(src._brain));
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->_brain;
}

std::string Cat::getType() const
{
    return this->_type;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl;
}

Brain * Cat::getBrain() const
{
    return this->_brain;
}