#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    std::cout << "-- construction --" << std::endl;
    IMateriaSource* src = new MateriaSource();
    std::cout << std::endl;

    std::cout << "-- learnMateria --" << std::endl;
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    std::cout << std::endl;

    std::cout << "-- new Character --" << std::endl;
    ICharacter* me = new Character("me");
    std::cout << std::endl;

    std::cout << "-- equip --" << std::endl;
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    std::cout << std::endl;

    std::cout << "-- new Character --" << std::endl;
    ICharacter* bob = new Character("bob");
    std::cout << std::endl;

    std::cout << "-- use --" << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);
    std::cout << std::endl;

    std::cout << "-- unequip --" << std::endl;
    me->unequip(0);
    me->unequip(1);
    std::cout << std::endl;

    std::cout << "-- use after unequip --" << std::endl;
    me->use(0, *bob); // Should not do anything
    me->use(1, *bob); // Should not do anything
    std::cout << std::endl;

    std::cout << "-- re-equip --" << std::endl;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    std::cout << std::endl;

    std::cout << "-- use after re-equip --" << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);
    std::cout << std::endl;

    std::cout << "-- delete --" << std::endl;
    delete bob;
    delete me;
    delete src;

    return (0);
}
