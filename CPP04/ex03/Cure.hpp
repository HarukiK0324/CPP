#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
    private:
        const std::string _type;
    public:
        Cure();
        Cure(const Cure &src);
        Cure &operator=(const Cure &src);
        ~Cure();
        std::string const & getType() const;
        AMateria* clone() const;
        void use(ICharacter& target);
};


#endif