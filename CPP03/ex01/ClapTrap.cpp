#include "ClapTrap.hpp"

ClapTrap::ClapTrap( const std::string& name ) : name(name), hitPoints(init_HP), energyPoints(init_EP), attackDamage(init_AD)
{
    std::cout << "ClapTrap " << name << " created with constructor" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& src ) : name(src.name), hitPoints(src.hitPoints), energyPoints(src.energyPoints), attackDamage(src.attackDamage)
{
    std::cout << "ClapTrap " << name << " created with copy constructor" << std::endl;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& src )
{
    if (this != &src)
    {
        this->name = src.name;
        this->hitPoints = src.hitPoints;
        this->energyPoints = src.energyPoints;
        this->attackDamage = src.attackDamage;
    }
    std::cout << "ClapTrap " << name << " created with copy assignment operator" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name << " destroyed with destructor" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->hitPoints > 0 && this->energyPoints > 0)
    {
        this->energyPoints--;
        std::cout << "ClapTrap " << this->name << " attacks " << target << " with " << this->attackDamage << " points of damage!" << std::endl;
    }
    else if (this->hitPoints == 0)
        std::cout << "ClapTrap " << this->name << " is out of hit points!" << std::endl;
    else
        std::cout << "ClapTrap " << this->name << " is out of energy points!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints > 0)
    {
        if (amount > this->hitPoints)
            amount = this->hitPoints;
        this->hitPoints -= amount;
        std::cout << "ClapTrap " << this->name << " attacked, receiving " << amount << " points of damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->name << " is already out of hit points!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energyPoints > 0 && this->hitPoints > 0)
    {
        this->hitPoints += amount;
        this->energyPoints--;
        std::cout << "ClapTrap " << this->name << " repairs itself, regaining " << amount << " hit points!" << std::endl;
    }
    else if (this->hitPoints == 0)
        std::cout << "ClapTrap " << this->name << " is out of hit points, unable to repair itself!" << std::endl;
    else
        std::cout << "ClapTrap " << this->name << " is out of energy points, unable to repair itself!" << std::endl;
}