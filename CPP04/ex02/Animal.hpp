#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
    protected:
        std::string _type;

        Animal();
        Animal(const Animal &src);
        Animal &operator=(const Animal &src);
    public:
        virtual ~Animal();
        virtual void makeSound() const;
        virtual std::string getType() const;
};

#endif