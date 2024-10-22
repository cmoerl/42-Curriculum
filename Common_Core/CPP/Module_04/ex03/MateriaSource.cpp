#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() {
    std::cout << "MateriaSource default constructor" << std::endl;
    for (int i = 0; i < 4; i++)
        _materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy) {
    std::cout << "MateriaSource copy constructor" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (copy._materias[i])
            _materias[i] = copy._materias[i]->clone();
        else
            _materias[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator = (const MateriaSource &copy) {
    std::cout << "MateriaSource copy assignment operator" << std::endl;
    if (this != &copy) {
        for (int i = 0; i < 4; i++) {
            if (_materias[i])
                delete _materias[i];
            if (copy._materias[i]) {
                _materias[i] = copy._materias[i]->clone();
            }
            else 
                _materias[i] = NULL;
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource destructor" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (_materias[i])
            delete _materias[i];
    }
}

// store the address?
void        MateriaSource::learnMateria(AMateria* materia) {
    if (!materia) {
        std::cerr << "Error: No Materia to be learned" << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++) {
        if (!_materias[i]) {
            _materias[i] = materia->clone();
            return ;
        }
    }
    std::cerr << "Error: No empty slot to learn Materia" << std::endl;
}

AMateria    *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++) {
        if (_materias[i] && _materias[i]->getType() == type)
            return (_materias[i]->clone());
    }
    std::cerr << "Error: Materia type unknown" << std::endl;
    return (NULL);
}
