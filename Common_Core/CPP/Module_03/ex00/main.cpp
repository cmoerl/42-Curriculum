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

    std::cout << std::endl;
    printClapTrap(clap);
    printClapTrap(trap);
    std::cout << std::endl;

    clap.attack("enemy");
    printClapTrap(clap);
    printClapTrap(trap);
    std::cout << std::endl;

    clap.takeDamage(5);
    printClapTrap(clap);
    printClapTrap(trap);
    std::cout << std::endl;

    clap.beRepaired(2);
    printClapTrap(clap);
    printClapTrap(trap);
    std::cout << std::endl;

    trap.beRepaired(10);
    printClapTrap(clap);
    printClapTrap(trap);
    std::cout << std::endl;

    trap.attack("enemy");
    printClapTrap(clap);
    printClapTrap(trap);
    std::cout << std::endl;

    trap.takeDamage(10);
    printClapTrap(clap);
    printClapTrap(trap);
    std::cout << std::endl;

    trap.attack("enemy");
    trap.takeDamage(1);
    trap.beRepaired(5);
    printClapTrap(clap);
    printClapTrap(trap);
    std::cout << std::endl;

    for (int i = 0; i < 9; i++)
        clap.attack("enemy");
    printClapTrap(clap);
    printClapTrap(trap);
    std::cout << std::endl;

    return (0);
}
