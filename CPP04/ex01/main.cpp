#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Animal *animals[100];
    int i = 0;
    for (;i < 50;i++)
    {
        animals[i] = new Dog();
    }
    for (;i < 100;i++)
    {
        animals[i] = new Cat();
    }
    static_cast<Dog*>(animals[0])->getBrain()->setIdea(0, "Idea0");
    std::cout << static_cast<Dog*>(animals[0])->getBrain()->getIdea(0) << std::endl;
    for(i = 0;i < 100;i++)
    {
        delete animals[i];
    }

    return 0;
}