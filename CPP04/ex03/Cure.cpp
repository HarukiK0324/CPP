#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure default constructor called" <<  std::endl;
}

Cure::Cure(const Cure &src) : AMateria(src)
{
    std::cout << "Cure copy constructor called" << std::endl;
    *this = src;
}

Cure &Cure::operator=(const Cure &src)
{
    std::cout << "Cure assignment operator called" << std::endl;
    if (this != &src)
    {
        AMateria::operator=(src);
    }
    return *this;
}

Cure::~Cure()
{
    std::cout << "Cure destructor called" << std::endl;
}

std::string const & Cure::getType() const
{
    return AMateria::getType();
}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
