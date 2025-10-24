#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice"), _type("ice")
{
    std::cout << "Ice default constructor called" <<  std::endl;
}

Ice::Ice(const Ice &src) : _type(src._type)
{
    std::cout << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &src)
{
    std::cout << "Ice assignment operator called" << std::endl;
    if (this != &src)
    {
    }
    return *this;
}

Ice::~Ice()
{
    std::cout << "Ice destructor called" << std::endl;
}

std::string const & Ice::getType() const
{
    return _type;
}

AMateria* Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
