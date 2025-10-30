#include "Weapon.hpp"

const std::string& Weapon::getType()
{
    return this->type;
}

void Weapon::setType(std::string type)
{
    this->type = type;
}

Weapon::Weapon(std::string type) : type(type)
{
    std::cout << this->type << " is created." << std::endl;
}

Weapon::~Weapon()
{
    std::cout << this->type << " is destroyed." << std::endl;
}
