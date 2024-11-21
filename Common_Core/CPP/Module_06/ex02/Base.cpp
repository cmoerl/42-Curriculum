#include "Base.hpp"

Base::~Base() {
    std::cout << "Base deconstructor" << std::endl;
}

Base*   generate(void) {
    
}

void    identify(Base* p);

void    identify(Base& p);
