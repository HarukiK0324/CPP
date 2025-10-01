#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
    public:
        void announce( void );
        static Zombie* newZombie( std::string name );
        static void randomChump( std::string name );
        Zombie(std::string name);
        ~Zombie(void);
    private:
        std::string name;
};

#endif