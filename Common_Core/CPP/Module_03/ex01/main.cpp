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

    printScavTrap(scav);
    printScavTrap(trap);
    std::cout << "\n";

    scav.attack("enemy");
    scav.takeDamage(5);
    printScavTrap(scav);
    printScavTrap(trap);
    std::cout << "\n";

    scav.beRepaired(2);
    trap.beRepaired(10);
    printScavTrap(scav);
    printScavTrap(trap);
    std::cout << "\n";

    trap.attack("enemy");
    trap.takeDamage(10);
    printScavTrap(scav);
    printScavTrap(trap);
    std::cout << "\n";

    trap.attack("enemy");
    trap.takeDamage(1);
    trap.beRepaired(5);
    printScavTrap(scav);
    printScavTrap(trap);
    std::cout << "\n";

    for (int i = 0; i < 9; i++)
        scav.attack("enemy");
    printScavTrap(scav);
    printScavTrap(trap);
    std::cout << "\n";

    scav.guardGate();
    trap.guardGate();
    printScavTrap(scav);
    printScavTrap(trap);
    std::cout << "\n";

    return (0);
}
