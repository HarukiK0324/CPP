#include "ScavTrap.hpp"

ScavTrap::ScavTrap( const std::string& name) : ClapTrap(name)
{
    this->hitPoints = init_HP;
    this->energyPoints = init_EP;
    this->attackDamage = init_AD;
    std::cout << "ScavTrap " << name << " created with constructor" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& src ) : ClapTrap(src)
{
    std::cout << "ScavTrap " << this->name << " created with copy constructor" << std::endl;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& src )
{
    if (this != &src)
        ClapTrap::operator=(src);
    std::cout << "ScavTrap " << this->name << " created with copy assignment operator" << std::endl;
    return *this;
}