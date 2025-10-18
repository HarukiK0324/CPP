#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat default constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = src;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
    std::cout << "WrongCat assignment operator called" << std::endl;
    if(this != &src)
    {
        this->type = src.type;
    }
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

std::string WrongCat::getType() const
{
    return this->type;
}

void WrongCat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl;
}