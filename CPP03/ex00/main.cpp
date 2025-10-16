#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapA("ClapA");
    ClapTrap clapB("ClapB");

    clapA.attack("ClapB");
    clapB.takeDamage(2);
    clapB.beRepaired(5);
    clapB.attack("ClapA");
    clapA.takeDamage(0);
    for(int i = 0; i < 10; i++)
        clapA.attack("ClapB");
}