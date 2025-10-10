#include "Zombie.hpp"

int main()
{
    Zombie zombie("Zombie1");
    zombie.announce();

    Zombie* zombie2 = Zombie::newZombie("Zombie2");
    zombie2->announce();
    delete zombie2;

    Zombie::randomChump("Zombie3");
    return 0;
}