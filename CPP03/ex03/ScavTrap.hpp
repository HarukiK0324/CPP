#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
    protected:
        static const unsigned int init_HP = 100;
        static const unsigned int init_EP = 50;
        static const unsigned int init_AD = 20;
    public:
        ScavTrap( const std::string& name);
        ScavTrap( const ScavTrap& src );
        ScavTrap& operator=( const ScavTrap& src );
        ~ScavTrap();
        void attack(const std::string& target);
        void guardGate();
    private:
        const unsigned int init_HP = 100;
};

#endif