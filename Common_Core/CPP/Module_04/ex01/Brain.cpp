#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructor" << std::endl;
    for (int i = 0; i < 100; i++)
        _ideas[i] = "";
}

Brain::Brain(const Brain &copy) {
    std::cout << "Brain copy constructor" << std::endl;
    for (int i = 0; i < 100; i++)
        _ideas[i] = copy._ideas[i];
}

// remember to delete old brain if existing
Brain &Brain::operator = (const Brain &copy) {
    std::cout << "Brain copy assignment operator" << std::endl;
    if (this != &copy) {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = copy._ideas[i];
    }
    return (*this);
}

Brain::~Brain() {
    std::cout << "Brain destructor" << std::endl;
}

std::string *Brain::getIdeas() const {
    return (const_cast<std::string*>(_ideas));
}

void        Brain::setIdeas(const std::string *ideas) {
    for (int i = 0; i < 100; i++)
        _ideas[i] = ideas[i];
}
