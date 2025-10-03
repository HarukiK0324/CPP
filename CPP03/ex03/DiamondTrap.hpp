#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FlagTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FlagTrap {
    private:
        std::string name;
    public:
        void whoAmI();

}

#endif