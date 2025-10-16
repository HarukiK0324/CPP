#include "FragTrap.hpp"

int main()
{
    FragTrap fragA("FragA");
    FragTrap fragB("FragB");

    fragA.attack("FragB");
    fragB.takeDamage(20);
    fragB.beRepaired(50);
    fragB.attack("FragA");
    fragA.takeDamage(0);
    fragA.highFivesGuys();
    fragB.highFivesGuys();
}