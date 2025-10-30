#include "ScavTrap.hpp"

int main()
{
    ScavTrap ScavA("ScavA");
    ScavTrap ScavB("ScavB");

    ScavA.attack("ScavB");
    ScavB.takeDamage(20);
    ScavB.beRepaired(50);
    ScavB.attack("ScavA");
    ScavA.takeDamage(0);
    ScavA.guardGate();
}
