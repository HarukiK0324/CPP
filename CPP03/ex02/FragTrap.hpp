#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    private:
        static const unsigned int init_HP = 100;
        static const unsigned int init_EP = 50;
        static const unsigned int init_AD = 20;
    public:
        FragTrap(const std::string& name);
        FragTrap(const FragTrap& src);
        FragTrap& operator=(const FragTrap& src);
        ~FragTrap();
        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif
