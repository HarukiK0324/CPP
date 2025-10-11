#include "Zombie.hpp"

void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie() : name("")
{
    std::cout << "Default constructor is called" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << name << " is destroyed" << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}
