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
    {
        ClapTrap::operator=(src);
    }
    std::cout << "ScavTrap " << this->name << " created with copy assignment operator" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->name << " destroyed with destructor" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->hitPoints > 0 && this->energyPoints > 0)
    {
        this->energyPoints--;
        std::cout << "ScavTrap " << this->name << " attacks " << target << " with " << this->attackDamage << " points of damage!" << std::endl;
    }
    else if (this->hitPoints == 0)
        std::cout << "ScavTrap " << this->name << " is out of hit points!" << std::endl;
    else
        std::cout << "ScavTrap " << this->name << " is out of energy points!" << std::endl;
}

void ScavTrap::guardGate()
{
    if(this->hitPoints == 0)
        std::cout << "ScavTrap " << this->name << " is out of hit points!" << std::endl;
    else if(this->energyPoints == 0)
        std::cout << "ScavTrap " << this->name << " is out of energy points!" << std::endl;
    else
        std::cout << "ScavTrap " << this->name << "  is now in Gate keeper mode, guarding the gate!" << std::endl;
}
