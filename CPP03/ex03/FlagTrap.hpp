#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP

#include "ClapTrap.hpp"

#define init_FT_HP 100
#define init_FT_EP 50
#define init_FT_AD 20

class FlagTrap : public ClapTrap {
    public:
        FlagTrap(const std::string& name);
        FlagTrap(const FlagTrap& src);
        FlagTrap& operator=(const FlagTrap& src);
        ~FlagTrap();
        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif