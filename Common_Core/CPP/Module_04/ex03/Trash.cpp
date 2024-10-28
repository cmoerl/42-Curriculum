#include "Trash.hpp"
#include <cstddef>

Trash::Trash() : trash(NULL) {}

Trash::Trash(const Trash& other) : trash(NULL) {
    *this = other;
}

Trash& Trash::operator=(const Trash& other) {
    if (this != &other) {
        cleanTrash();
        s_trash *tmp = other.trash;
        while (tmp) {
            addToTrash(tmp->materia);
            tmp = tmp->next;
        }
    }
    return *this;
}

Trash::~Trash() {
    cleanTrash();
}

void Trash::addToTrash(AMateria *materia) {
    s_trash *current = trash;
    while (current) {
        if (current->materia == materia)
            return;
        current = current->next;
    }
    s_trash *newTrash = new s_trash;
    newTrash->materia = materia;
    newTrash->next = trash;
    trash = newTrash;
}

void Trash::cleanTrash () {
    if (!trash)
        return;
    s_trash *tmp = trash;
    while (tmp) {
        s_trash *next = tmp->next;
        delete tmp->materia;
        tmp->materia = NULL;
        delete tmp;
        tmp = NULL;
        tmp = next;
    }
    trash = NULL;
}
