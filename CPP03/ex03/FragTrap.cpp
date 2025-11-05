#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    this->hitPoints = init_HP;
    this->energyPoints = init_EP;
    this->attackDamage = init_AD;
    std::cout << "FragTrap " << name << " created with constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
    *this = src;
    std::cout << "FragTrap " << this->name << " created with copy constructor" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& src)
{
    if (this != &src)
    {
        ClapTrap::operator=(src);
        this->hitPoints = src.hitPoints;
        this->energyPoints = src.energyPoints;
        this->attackDamage = src.attackDamage;
    }
    std::cout << "FragTrap " << this->name << " created with copy assignment operator" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->name << " destroyed with destructor" << std::endl;
}

void FragTrap::attack(const std::string& target)
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

void FragTrap::highFivesGuys(void)
{
    if(this->hitPoints == 0)
        std::cout << "FragTrap " << this->name << " is out of hit points!" << std::endl;
    else if(this->energyPoints == 0)
        std::cout << "FragTrap " << this->name << " is out of energy points!" << std::endl;
    else
        std::cout << "FragTrap " << this->name << " is requesting a high five!" << std::endl;
}
