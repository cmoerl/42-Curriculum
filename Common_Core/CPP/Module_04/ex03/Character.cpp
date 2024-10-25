#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(): _name(""), _trashCount(0) {
    std::cout << "Character default constructor" << std::endl;
    for (int i = 0; i < 4; i++)
        _slots[i] = NULL;
    for (int i = 0; i < 100; i++)
        _trash[i] = NULL;
}

Character::Character(std::string name): _name(name), _trashCount(0) {
    std::cout << "Character parameterised constructor" << std::endl;
    for (int i = 0; i < 4; i++)
        _slots[i] = NULL;
    for (int i = 0; i < 100; i++)
        _trash[i] = NULL;
}

Character::Character(const Character &copy): _name(copy._name), _trashCount(0) {
    std::cout << "Character copy constructor" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (copy._slots[i])
            _slots[i] = copy._slots[i]->clone();
        else
            _slots[i] = NULL;
    }
    for (int i = 0; i < 100; i++)
        _trash[i] = NULL;
}

Character &Character::operator = (const Character &copy) {
    std::cout << "Character copy assignment constructor" << std::endl;
    if (this != &copy) {
        _name = copy._name;
        _trashCount = 0;
        for (int i = 0; i < 4; i++) {
            if (_slots[i])
                delete _slots[i];
            if (copy._slots[i])
                _slots[i] = copy._slots[i]->clone();
            else
                _slots[i] = NULL;
        }
        for (int i = 0; i < 100; i++)
            _trash[i] = NULL;
    }
    return (*this);
}

Character::~Character() {
    std::cout << "Character destructor" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (_slots[i])
            delete _slots[i];
    }
    for (int i = 0; i < _trashCount; i++) {
        if (_trash[i])
            delete _trash[i];
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
            for (int j = 0; j < 100; j++) {
                if (_trash[j] == m)
                    break ;
                else if (!_trash[j]) {
                    _trash[j] = m;
                    _trashCount++;
                    break ;
                }
            }
            return ;
        }
    }
    std::cerr << "Error: Slots are full" << std::endl;
    for (int i = 0; i < 100; i++) {
        if (_trash[i] == m)
            break ;
        else if (!_trash[i]) {
            _trash[i] = m;
            _trashCount++;
            break ;
        }
    }
}

void        Character::unequip(int idx) { 
    if (idx > 3 || idx < 0 || !_slots[idx]) {
        std::cerr << "Error: Could not unequip" << std::endl;
        return ;
    }
    for (int i = 0; i < 100; i++) {
            if (_trash[i] == _slots[idx])
                break ;
            else if (!_trash[i]) {
                _trash[i] = _slots[idx];
                _trashCount++;
                break ;
            }
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
