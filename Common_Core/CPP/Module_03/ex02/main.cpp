#include "FragTrap.hpp"

void    printFragTrap(FragTrap &robot)
{  
    std::cout << robot.getName() << ": hit points (" << robot.getHitPoints() 
    << "), energy points (" << robot.getEnergyPoints() << ")" << std::endl;
}

int main(void)
{
    FragTrap    frag("frag");
    FragTrap    trap("trap");

    std::cout << std::endl;
    printFragTrap(frag);
    printFragTrap(trap);
    std::cout << std::endl;

    frag.highFivesGuys();
    trap.highFivesGuys();
    printFragTrap(frag);
    printFragTrap(trap);
    std::cout << std::endl;

    frag.attack("enemy");
    printFragTrap(frag);
    printFragTrap(trap);
    std::cout << std::endl;

    trap.takeDamage(100);
    printFragTrap(frag);
    printFragTrap(trap);
    std::cout << std::endl;

    trap.attack("enemy");
    trap.takeDamage(1);
    trap.beRepaired(5);
    printFragTrap(frag);
    printFragTrap(trap);
    std::cout << std::endl;

    for (int i = 0; i < 100; i++)
        frag.attack("enemy");
    printFragTrap(frag);
    printFragTrap(trap);
    std::cout << std::endl;

    frag.highFivesGuys();
    trap.highFivesGuys();
    printFragTrap(frag);
    printFragTrap(trap);
    std::cout << std::endl;

    return (0);
}
