#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
    private:
        std::string name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;
        static const unsigned int init_HP = 10;
        static const unsigned int init_EP = 10;
        static const unsigned int init_AD = 0;
    public:
        ClapTrap( const std::string& name );
        ClapTrap( const ClapTrap& src );
        ClapTrap& operator=( const ClapTrap& src );
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif
