#include "ScavTrap.hpp"

void    printScavTrap(ScavTrap &robot)
{  
    std::cout << robot.getName() << ": hit points (" << robot.getHitPoints() 
    << "), energy points (" << robot.getEnergyPoints() << ")" << std::endl;
}

int main(void)
{
    ScavTrap    scav("scav");
    ScavTrap    trap("trap");

    std::cout << std::endl;
    printScavTrap(scav);
    printScavTrap(trap);
    std::cout << std::endl;

    scav.guardGate();
    trap.guardGate();
    printScavTrap(scav);
    printScavTrap(trap);
    std::cout << std::endl;

    scav.attack("enemy");
    printScavTrap(scav);
    printScavTrap(trap);
    std::cout << std::endl;

    scav.takeDamage(5);
    printScavTrap(scav);
    printScavTrap(trap);
    std::cout << std::endl;

    scav.beRepaired(2);
    printScavTrap(scav);
    printScavTrap(trap);
    std::cout << std::endl;

    trap.beRepaired(10);
    printScavTrap(scav);
    printScavTrap(trap);
    std::cout << std::endl;

    trap.attack("enemy");
    trap.takeDamage(100);
    printScavTrap(scav);
    printScavTrap(trap);
    std::cout << std::endl;

    trap.attack("enemy");
    trap.takeDamage(1);
    trap.beRepaired(5);
    printScavTrap(scav);
    printScavTrap(trap);
    std::cout << std::endl;

    for (int i = 0; i < 49; i++)
        scav.attack("enemy");
    printScavTrap(scav);
    printScavTrap(trap);
    std::cout << std::endl;

    scav.guardGate();
    trap.guardGate();
    printScavTrap(scav);
    printScavTrap(trap);
    std::cout << std::endl;

    return (0);
}
