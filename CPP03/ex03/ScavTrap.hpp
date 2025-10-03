#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#define init_ST_HP 100
#define init_ST_EP 50
#define init_ST_AD 20

class ScavTrap : public ClapTrap {
    public:
        ScavTrap( const std::string& name);
        ScavTrap( const ScavTrap& src );
        ScavTrap& operator=( const ScavTrap& src );
        ~ScavTrap();
        void attack(const std::string& target);
        void guardGate();
};

#endif