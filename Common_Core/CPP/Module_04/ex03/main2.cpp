#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"


int main() {
  {
    std::cout << "0. TESTING SUBJECT MAIN:" << std::endl;
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter *me = new Character("me");
    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    std::cout << std::endl;
  }
  {
    std::cout << "-Checking deep Copies" << std::endl;
    std::cout << "--copy assignment" << std::endl;
    ICharacter *bob = new Character("bob");
    // Character *bob = new Character("bob");
    bob->equip(new Cure());
    // Character *robbert = new Character(*bob);
    ICharacter *robbert = new Character(*dynamic_cast<Character *>(bob));
    // std::cout << "MATERIAS OF BOB: " << std::endl;
    // print_mat_adress(bob);
    // std::cout << "MATERIAS OF ROBBERT: " << std::endl;
    // robbert->print_mat_adress();
    delete robbert;
    delete bob;
    std::cout << std::endl;
    std::cout << "--copy constructor" << std::endl;
    ICharacter *steve = new Character("steve");
    ICharacter *jim = new Character("jim");
    steve->equip(new Ice());
    *jim = *steve;
    // std::cout << "MATERIAS OF JIM: " << std::endl;
    // jim->print_mat_adress();
    // std::cout << "MATERIAS OF STEVE: " << std::endl;
    // steve->print_mat_adress();
    delete jim;
    delete steve;
    std::cout << std::endl;
  }
  {
    std::cout << "-Testing LearnMateria. More than 4 spells" << std::endl;
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    AMateria *mat = new Cure();
    src->learnMateria(mat);
    delete src;
    std::cout << std::endl;
  }
  {
    std::cout << "-Testing CreateMateria. Unknown Materia" << std::endl;
    AMateria *test;
    IMateriaSource *book = new MateriaSource();
    book->learnMateria(new Cure());
    book->learnMateria(new Ice());
    ICharacter *bob = new Character("bob");
    test = book->createMateria("cure");
    bob->equip(test);
    test = book->createMateria("ice");
    bob->equip(test);
    test = book->createMateria("air");
    bob->equip(test);
    delete book;
    delete bob;
    std::cout << std::endl;
  }
  {
    std::cout << "-Testing equip/unequip and Max equip" << std::endl;
    AMateria *test;
    IMateriaSource *book = new MateriaSource();
    book->learnMateria(new Cure());
    book->learnMateria(new Ice());
    ICharacter *bob = new Character("bob");
    ICharacter *alex = new Character("alex");
    test = book->createMateria("cure");
    bob->equip(test);
    test = book->createMateria("ice");
    bob->equip(test);
    bob->equip(test);
    bob->equip(test);
    bob->equip(test);
    bob->equip(test);
    bob->equip(test);
    bob->equip(test);
    bob->equip(test);
    bob->equip(test);
    alex->equip(test);
    delete bob;
    delete alex;
    delete book;
  }
  {
    std::cout << "-Testing use function on different character" << std::endl;
    IMateriaSource *book = new MateriaSource();
    book->learnMateria(new Ice());
    book->learnMateria(new Cure());
    ICharacter *Charlie = new Character("charlie");
    ICharacter *Mac = new Character("mac");
    Charlie->equip(book->createMateria("ice"));
    Mac->equip(book->createMateria("cure"));
    Charlie->use(0, *Mac);
    Mac->use(0, *Charlie);
    std::cout << "--Invalid Index in use function" << std::endl;
    Mac->use(-5, *Mac);
    Mac->use(2, *Mac);
    Mac->use(2000, *Mac);
    Mac->use(2147483647, *Mac);
    Mac->use('a', *Mac);
    Mac->use('\r', *Mac);
    delete book;
    delete Mac;
    delete Charlie;
  }
  return (0);
}
