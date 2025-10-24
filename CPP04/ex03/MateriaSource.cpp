#include "AMateria.hpp"
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < maxMaterias; i++)
        this->Materias[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
    *this = src;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
    if (this != &src)
    {
        for (int i = 0; i < maxMaterias; i++)
        {
            if (this->Materias[i])
                delete this->Materias[i];
            if (src.Materias[i])
                this->Materias[i] = src.Materias[i]->clone();
            else
                this->Materias[i] = nullptr;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < maxMaterias; i++)
    {
        if (this->Materias[i])
            delete this->Materias[i];
    }
}

void MateriaSource::learnMateria(AMateria* materia)
{
    for (int i = 0; i < maxMaterias; i++)
    {
        if (this->Materias[i] == nullptr)
        {
            this->Materias[i] = materia;
            return;
        }
    }
    std::cerr << "MateriaSource inventory full, cannot learn more materias." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for(int i = 0;i < maxMaterias;i++)
    {
        if(this->Materias[i] && this->Materias[i]->getType() == type)
        {
            return this->Materias[i]->clone();
        }
    }
    std::cerr << "MateriaSource inventory full, cannot learn more materias." << std::endl;
    return nullptr;
}
