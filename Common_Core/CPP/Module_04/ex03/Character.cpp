#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(): _name("") {
    std::cout << "Character default constructor" << std::endl;
    for (int i = 0; i < 4; i++)
        _slots[i] = NULL;
}

Character::Character(std::string name): _name(name) {
    std::cout << "Character parameterised constructor" << std::endl;
    for (int i = 0; i < 4; i++)
        _slots[i] = NULL;
}

Character::Character(const Character &copy) {
    std::cout << "Character copy constructor" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (copy._slots[i])
            _slots[i] = copy._slots[i]->clone();
        else
            _slots[i] = NULL;
    }
}

Character &Character::operator = (const Character &copy) {
    std::cout << "Character copy assignment constructor" << std::endl;
    if (this != &copy) {
        for (int i = 0; i < 4; i++) {
            if (_slots[i])
                delete _slots[i];
            if (copy._slots[i])
                _slots[i] = copy._slots[i]->clone();
            else
                _slots[i] = NULL;
        }
    }
    return (*this);
}

Character::~Character() {
    std::cout << "Character destructor" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (_slots[i])
            delete _slots[i];
    }
}

std::string const &Character::getName() const {
    return (_name);
}

void        Character::equip(AMateria *m) {
    if (!m){
        std::cerr << "Error: No Materia to be learned" << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++) {
        if (!_slots[i]) {
            _slots[i] = m->clone();
            return ;
        }
    }
    std::cerr << "Error: Slots are full" << std::endl;
    delete (m);
}

// store the address?
void        Character::unequip(int idx) { 
    if (idx > 3 || idx < 0 || !_slots[idx]) {
        std::cerr << "Error: Could not unequip" << std::endl;
        return ;
    }
    _slots[idx] = NULL;
}

void        Character::use(int idx, ICharacter &target) {
    if (idx > 3 || idx < 0 || !_slots[idx]) {
        std::cerr << "Error: Could not use" << std::endl;
        return ;
    }
    _slots[idx]->use(target);
}
