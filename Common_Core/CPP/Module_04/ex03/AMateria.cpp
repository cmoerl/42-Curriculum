#include "AMateria.hpp"

AMateria::AMateria(): type("default") {
    std::cout << "AMateria default constructor" << std::endl;
}

AMateria::AMateria(std::string const & type): type(type) {
    std::cout << "AMateria parameterised constructor" << std::endl;
}

AMateria::AMateria(const AMateria &copy): type(copy.type) {
    std::cout << "AMateria copy constructor" << std::endl;
}

AMateria &AMateria::operator = (const AMateria &copy) {
    std::cout << "AMateria copy assigment operator" << std::endl;
    if (this != &copy) {
    //     type = copy.type;
    }
    return (*this);
}

AMateria::~AMateria() {
    std::cout << "AMateria destructor" << std::endl;
}

std::string const &AMateria::getType() const {
    return (type);
}

void    AMateria::use(ICharacter& target) {
    std::cout << "* Materia is used on " << target.getName() << " *" << std::endl;
}
