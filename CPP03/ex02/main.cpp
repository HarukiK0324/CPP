#include "ClapTrap.hpp"
#include "FlagTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    FlagTrap flagA("FlagA");
    FlagTrap flagB("FlagB");

    flagA.attack("FlagB");
    flagB.takeDamage(20);
    flagB.beRepaired(50);
    flagB.attack("FlagA");
    flagA.takeDamage(0);
    flagA.highFivesGuys();
    flagB.highFivesGuys();
}