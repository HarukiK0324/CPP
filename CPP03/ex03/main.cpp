#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap diamondA("DiamondA");
    DiamondTrap diamondB("DiamondB");

    diamondA.attack("ClapB");
    diamondB.takeDamage(20);
    diamondB.beRepaired(5);
    diamondB.attack("DiamondA");
    diamondA.takeDamage(0);

    diamondA.guardGate();
    diamondB.highFivesGuys();

    diamondA.whoAmI();
    diamondB.whoAmI();
}
