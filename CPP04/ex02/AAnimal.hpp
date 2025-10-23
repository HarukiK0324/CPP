#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
    protected:
        std::string _type;

        AAnimal();
        AAnimal(const AAnimal &src);
        AAnimal &operator=(const AAnimal &src);
    public:
        virtual ~AAnimal();
        virtual void makeSound() const;
        virtual std::string getType() const;
};

#endif