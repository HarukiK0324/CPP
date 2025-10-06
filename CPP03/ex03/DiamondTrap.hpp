#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FlagTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FlagTrap {
    private:
        std::string name;
    public:
        DiamondTrap(const std::string& name);
        DiamondTrap(const DiamondTrap& src);
        DiamondTrap& operator=(const DiamondTrap& src);
        ~DiamondTrap();
        void attack(const std::string& target);
        void whoAmI();

};

#endif