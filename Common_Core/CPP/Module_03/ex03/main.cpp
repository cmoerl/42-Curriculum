#include "DiamondTrap.hpp"

void    printDiamondTrap(DiamondTrap &robot, std::string name)
{  
    std::cout << name << ": hit points (" << robot.getHitPoints() 
    << "), energy points (" << robot.getEnergyPoints() << ")" << std::endl;
}

int main(void)
{
    DiamondTrap    diana("Diana");
    DiamondTrap    mono("Mono");

    std::cout << std::endl;
    printDiamondTrap(diana, "Diana");
    printDiamondTrap(mono, "Mono");
    std::cout << std::endl;

    diana.attack("enemy");
    printDiamondTrap(diana, "Diana");
    printDiamondTrap(mono, "Mono");
    std::cout << std::endl;

    diana.takeDamage(5);
    printDiamondTrap(diana, "Diana");
    printDiamondTrap(mono, "Mono");
    std::cout << std::endl;

    diana.beRepaired(2);
    printDiamondTrap(diana, "Diana");
    printDiamondTrap(mono, "Mono");
    std::cout << std::endl;

    mono.beRepaired(10);
    printDiamondTrap(diana, "Diana");
    printDiamondTrap(mono, "Mono");
    std::cout << std::endl;

    mono.attack("enemy");
    mono.takeDamage(110);
    printDiamondTrap(diana, "Diana");
    printDiamondTrap(mono, "Mono");
    std::cout << std::endl;

    mono.attack("enemy");
    mono.takeDamage(1);
    mono.beRepaired(5);
    printDiamondTrap(diana, "Diana");
    printDiamondTrap(mono, "Mono");
    std::cout << std::endl;

    for (int i = 0; i < 99; i++)
        diana.attack("enemy");
    printDiamondTrap(diana, "Diana");
    printDiamondTrap(mono, "Mono");
    std::cout << std::endl;

    diana.highFivesGuys();
    printDiamondTrap(diana, "Diana");
    printDiamondTrap(mono, "Mono");
    std::cout << std::endl;

    diana.whoAmI();
    std::cout << std::endl;

    return (0);
}
