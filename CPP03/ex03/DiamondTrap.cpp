#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
    this->hitPoints = FragTrap::init_HP;
    this->energyPoints = ScavTrap::init_EP;
    this->attackDamage = FragTrap::init_AD;
    std::cout << "DiamondTrap " << name << " created with constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(src), ScavTrap(src), FragTrap(src), name(src.name)
{
    *this = src;
    std::cout << "DiamondTrap " << name << " created with copy constructor" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src)
{
    if (this != &src)
    {
        FragTrap::operator=(src);
        ScavTrap::operator=(src);
        ClapTrap::operator=(src);
        this->hitPoints = src.hitPoints;
        this->energyPoints = src.energyPoints;
        this->attackDamage = src.attackDamage;
    }
    std::cout << "DiamondTrap " << name << " created with copy assignment operator" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->name << " destroyed with destructor" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    if (this->hitPoints > 0 && this->energyPoints > 0)
    {
        this->energyPoints--;
        std::cout << "FragTrap " << this->name << " attacks " << target << " with " << this->attackDamage << " points of damage!" << std::endl;
    }
    else if (this->hitPoints == 0)
        std::cout << "FragTrap " << this->name << " is out of hit points!" << std::endl;
    else
        std::cout << "FragTrap " << this->name << " is out of energy points!" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << this->name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}
