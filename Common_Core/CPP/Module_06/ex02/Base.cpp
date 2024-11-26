#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {
    std::cout << "Base deconstructor" << std::endl;
}

Base*   generate(void) {
    srand(time(NULL));
    int random = rand() % 3;
    if (random == 0) {
        return new A();
    } else if (random == 1) {
        return new B();
    } else {
        return new C();
    }
}

void    identify(Base* p) {
    if (!p) {
        std::cout << "Nullptr" << std::endl;
        return;
    }
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    }
    else {
        std::cout << "Unknown" << std::endl;
    }
}

void    identify(Base& p) {
    try {
        (void)dynamic_cast <A&>(p);
        std::cout << "A" << std::endl;
    } catch (std::exception &e) {
        try {
            (void)dynamic_cast <B&>(p);
            std::cout << "B" << std::endl;
        } catch (std::exception &e) {
            try {
                (void)dynamic_cast <C&>(p);
                std::cout << "C" << std::endl;
            } catch (std::exception &e) {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}
