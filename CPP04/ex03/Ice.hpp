#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
    private:
        const std::string _type;
    public:
        Ice();
        Ice(const Ice &src);
        Ice &operator=(const Ice &src);
        ~Ice();

        std::string const & getType() const;
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif