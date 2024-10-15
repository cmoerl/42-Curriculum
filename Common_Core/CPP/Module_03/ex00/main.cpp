#include "ClapTrap.hpp"

void    printClapTrap(ClapTrap &robot)
{
    std::cout << robot.getName() << ": hit points (" << robot.getHitPoints() 
    << "), energy points (" << robot.getEnergyPoints() << ")" << std::endl;
}

int main(void)
{
    ClapTrap    clap("clap");
    ClapTrap    trap("trap");

    printClapTrap(clap);
    printClapTrap(trap);

    clap.attack("enemy");
    clap.takeDamage(5);
    printClapTrap(clap);
    printClapTrap(trap);

    clap.beRepaired(2);
    trap.beRepaired(10);
    printClapTrap(clap);
    printClapTrap(trap);

    trap.attack("enemy");
    trap.takeDamage(10);
    printClapTrap(clap);
    printClapTrap(trap);

    trap.attack("enemy");
    trap.takeDamage(1);
    trap.beRepaired(5);
    printClapTrap(clap);
    printClapTrap(trap);

    for (int i = 0; i < 9; i++)
        clap.attack("enemy");
    printClapTrap(clap);
    printClapTrap(trap);

    return (0);
}
