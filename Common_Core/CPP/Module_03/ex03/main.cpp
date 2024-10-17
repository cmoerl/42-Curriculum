#include "DiamondTrap.hpp"

void    printFragTrap(FragTrap &robot)
{  
    std::cout << robot.getName() << ": hit points (" << robot.getHitPoints() 
    << "), energy points (" << robot.getEnergyPoints() << ")" << std::endl;
}

int main(void)
{
    DiamondTrap    frag("frag");
    DiamondTrap    trap("trap");

    printFragTrap(frag);
    printFragTrap(trap);
    std::cout << "\n";

    frag.attack("enemy");
    frag.takeDamage(5);
    printFragTrap(frag);
    printFragTrap(trap);
    std::cout << "\n";

    frag.beRepaired(2);
    trap.beRepaired(10);
    printFragTrap(frag);
    printFragTrap(trap);
    std::cout << "\n";

    trap.attack("enemy");
    trap.takeDamage(10);
    printFragTrap(frag);
    printFragTrap(trap);
    std::cout << "\n";

    trap.attack("enemy");
    trap.takeDamage(1);
    trap.beRepaired(5);
    printFragTrap(frag);
    printFragTrap(trap);
    std::cout << "\n";

    for (int i = 0; i < 9; i++)
        frag.attack("enemy");
    printFragTrap(frag);
    printFragTrap(trap);
    std::cout << "\n";

    frag.highFivesGuys();
    printFragTrap(frag);
    printFragTrap(trap);
    std::cout << "\n";

    frag.whoAmI();

    return (0);
}
