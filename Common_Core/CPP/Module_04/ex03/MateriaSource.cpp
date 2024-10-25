#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() {
    std::cout << "MateriaSource default constructor" << std::endl;
    _trashCount = 0;
    for (int i = 0; i < 4; i++)
        _materias[i] = NULL;
    for (int i = 0; i < 100; i++)
        _trash[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy): _trashCount(0) {
    std::cout << "MateriaSource copy constructor" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (copy._materias[i])
            _materias[i] = copy._materias[i]->clone();
        else
            _materias[i] = NULL;
    }
    for (int i = 0; i < 100; i++)
        _trash[i] = NULL;
}

MateriaSource &MateriaSource::operator = (const MateriaSource &copy) {
    std::cout << "MateriaSource copy assignment operator" << std::endl;
    if (this != &copy) {
        _trashCount = 0;
        for (int i = 0; i < 4; i++) {
            if (_materias[i])
                delete _materias[i];
            if (copy._materias[i]) {
                _materias[i] = copy._materias[i]->clone();
            }
            else 
                _materias[i] = NULL;
        }
        for (int i = 0; i < 100; i++)
            _trash[i] = NULL;
    }
    return (*this);
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource destructor" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (_materias[i])
            delete _materias[i];
    }
    for (int i = 0; i < _trashCount; i++) {
        if (_trash[i])
            delete _trash[i];
    }
}

void        MateriaSource::learnMateria(AMateria* materia) {
    if (!materia) {
        std::cerr << "Error: No Materia to be learned" << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++) {
        if (!_materias[i]) {
            _materias[i] = materia->clone();
            for (int j = 0; j < 100; j++){
                if (_trash[j] == materia)
                    break ;
                else if (!_trash[j]) {
                    _trash[j] = materia;
                    _trashCount++;
                    break ;
                }
            }
            return ;
        }
    }
    std::cerr << "Error: No empty slot to learn Materia" << std::endl;
    for (int j = 0; j < 100; j++){
        if (_trash[j] == materia)
            break ;
        else if (!_trash[j]) {
            _trash[j] = materia;
            _trashCount++;
            break ;
        }
    }
}

AMateria    *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++) {
        if (_materias[i] && _materias[i]->getType() == type)
            return (_materias[i]->clone());
    }
    std::cerr << "Error: Materia type unknown" << std::endl;
    return (NULL);
}
