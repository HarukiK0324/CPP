#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

#define init_HP 100
#define init_EP 50
#define init_AD 20

class ScavTrap : public ClapTrap {
    private:
    public:
        ScavTrap( const std::string& name);
        ScavTrap( const ScavTrap& src );
        ScavTrap& operator=( const ScavTrap& src );
        ~ScavTrap();
        void attack(const std::string& target);
        void guardGate();
};

#endif