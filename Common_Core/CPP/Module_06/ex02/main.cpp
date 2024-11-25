#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
    Base *base = generate();
    identify(base);
    identify(*base);
    delete base;

    sleep(1);

    Base *base2 = generate();
    identify(base2);
    identify(*base2);
    delete base2;
    return 0;
}
