#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("")
{
    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src )
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = src;
}

AAnimal &AAnimal::operator=(const AAnimal &src)
{
    std::cout << "AAnimal assignment operator called" << std::endl;
    if (this != &src)
    {
        this->_type = src._type;
    }
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
    return this->_type;
}

// void AAnimal::makeSound() const
// {
//     std::cout << "AAnimal sound" << std::endl;
// }
