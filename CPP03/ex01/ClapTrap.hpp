#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

#define init_HP 10
#define init_EP 10
#define init_AD 0

class ClapTrap {
    protected:
        std::string name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;
    public:
        ClapTrap( const std::string& name );
        ClapTrap( const ClapTrap& src );
        ClapTrap& operator=( const ClapTrap& src );
        virtual ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif