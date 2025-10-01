#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
    public:
        void announce( void );
        Zombie* newZombie( std::string name );
        void randomChump( std::string name );
        static Zombie* zombieHorde( int N, std::string name );
        Zombie(std::string name);
        ~Zombie(void);
    private:
        std::string name;
};

#endif