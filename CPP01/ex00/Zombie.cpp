#include "Zombie.hpp"

void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name) : name(name)
{
    std::cout << name << " is created" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << name << " is destroyed" << std::endl;
}