#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
    protected:
        std::string _type;

    public:
        AAnimal();
        AAnimal(const AAnimal &src);
        AAnimal &operator=(const AAnimal &src);
        virtual ~AAnimal();
        virtual void makeSound() const = 0;
        virtual std::string getType() const;
};

#endif