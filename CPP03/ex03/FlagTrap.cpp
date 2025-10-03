#include "FlagTrap.hpp"

FlagTrap::FlagTrap(const std::string& name) : ClapTrap(name)
{
    this->hitPoints = init_FT_HP;
    this->energyPoints = init_FT_EP;
    this->attackDamage = init_FT_AD;
    std::cout << "FlagTrap " << name << " created with constructor" << std::endl;
}

FlagTrap::FlagTrap(const FlagTrap& src) : ClapTrap(src.name)
{
    this->hitPoints = src.hitPoints;
    this->energyPoints = src.energyPoints;
    this->attackDamage = src.attackDamage;
    std::cout << "FlagTrap " << this->name << " created with copy constructor" << std::endl;
}

FlagTrap& FlagTrap::operator=(const FlagTrap& src)
{
    if (this != &src)
    {
        this->name = src.name;
        this->hitPoints = src.hitPoints;
        this->energyPoints = src.energyPoints;
        this->attackDamage = src.attackDamage;
    }
    std::cout << "FlagTrap " << this->name << " created with copy assignment operator" << std::endl;
    return *this;
}

FlagTrap::~FlagTrap()
{
    std::cout << "FlagTrap " << this->name << " destroyed with destructor" << std::endl;
}

void FlagTrap::attack(const std::string& target)
{
    if (this->hitPoints > 0 && this->energyPoints > 0)
    {
        this->energyPoints--;
        std::cout << "FlagTrap " << this->name << " attacks " << target << " with " << this->attackDamage << " points of damage!" << std::endl;
    }
    else if (this->hitPoints == 0)
        std::cout << "FlagTrap " << this->name << " is out of hit points!" << std::endl;
    else
        std::cout << "FlagTrap " << this->name << " is out of energy points!" << std::endl;
}

void FlagTrap::highFivesGuys(void)
{
    if(this->hitPoints == 0)
        std::cout << "FlagTrap " << this->name << " is out of hit points!" << std::endl;
    else if(this->energyPoints == 0)
        std::cout << "FlagTrap " << this->name << " is out of energy points!" << std::endl;
    else
        std::cout << "FlagTrap " << this->name << " is requesting a high five!" << std::endl;
}
