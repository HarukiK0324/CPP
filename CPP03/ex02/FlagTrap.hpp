#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP

#include "ClapTrap.hpp"

class FlagTrap : public ClapTrap {
    private:
        static const unsigned int init_HP = 100;
        static const unsigned int init_EP = 50;
        static const unsigned int init_AD = 20;
    public:
        FlagTrap(const std::string& name);
        FlagTrap(const FlagTrap& src);
        FlagTrap& operator=(const FlagTrap& src);
        ~FlagTrap();
        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif