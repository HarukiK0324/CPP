#include "AMateria.hpp"
#include "Character.hpp"

Character::Character() : _name("Default")
{
    for (int i = 0;i < maxInventory;i++)
        this->_inventory[i] = 0;
}

Character::Character(std::string name) : _name(name)
{
    for (int i = 0;i < maxInventory;i++)
        this->_inventory[i] = 0;
}

Character::Character(const Character &src) : _name(src._name)
{
    for (int i = 0;i < maxInventory;i++)
    {
        if (src._inventory[i])
            this->_inventory[i] = src._inventory[i]->clone();
        else
            this->_inventory[i] = 0;
    }
}

Character &Character::operator=(const Character &src)
{
    if (this != &src)
    {
        this->_name = src._name;
        for (int i = 0;i < maxInventory;i++)
        {
            if (this->_inventory[i])
                delete this->_inventory[i];
            if (src._inventory[i])
                this->_inventory[i] = src._inventory[i]->clone();
            else
                this->_inventory[i] = 0;
        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0;i < maxInventory;i++)
    {
        if (this->_inventory[i])
            delete this->_inventory[i];
    }
}

std::string const & Character::getName() const
{
    return this->_name;
}

void Character::equip(AMateria* m)
{
    for(int i = 0;i < maxInventory;i++)
    {
        if(!this->_inventory[i])
        {
            this->_inventory[i] = m;
            return;
        }
    }
    std::cerr << "Inventory full, cannot equip more materia." << std::endl;
}

void Character::unequip(int idx)
{
    if(idx < 0 || idx >= maxInventory)
    {
        std::cerr << "Invalid index to unequip." << std::endl;
        return;
    }
    else if(!this->_inventory[idx])
    {
        std::cerr << "No materia to unequip at this index." << std::endl;
        return;
    }
    this->_inventory[idx] = 0;
}
void Character::use(int idx, ICharacter& target)
{
    if(idx < 0 || idx >= maxInventory)
    {
        std::cerr << "Invalid index to use." << std::endl;
        return;
    }
    else if(!this->_inventory[idx])
    {
        std::cerr << "No materia to use at this index." << std::endl;
        return;
    }
    this->_inventory[idx]->use(target);
}
