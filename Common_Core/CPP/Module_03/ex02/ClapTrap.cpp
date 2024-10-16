#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap has been created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy): _name(copy._name), _hitPoints(copy._hitPoints), 
                        _energyPoints(copy._energyPoints), _attackDamage(copy._attackDamage) {
    if (this->getName().empty())
        std::cout << "Copy of ClapTrap has been created" << std::endl;
    else
        std::cout << "Copy of ClapTrap named " << this->getName() << " has been created" << std::endl;
}


ClapTrap &ClapTrap::operator = (const ClapTrap &copy)
{
    if (this != &copy)
    {
        this->_name = copy._name;
        this->_hitPoints = copy._hitPoints;
        this->_energyPoints = copy._energyPoints;
    }
    if (this->getName().empty())
        std::cout << "Copy of ClapTrap has been assigned" << std::endl;
    else
        std::cout << "Copy of ClapTrap named " << this->getName() << " has been assigned" << std::endl;
    return (*this);
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap named " << name << " has been created" << std::endl;
}

ClapTrap::~ClapTrap() {
    if (this->getName().empty())
        std::cout << "ClapTrap has been destroyed" << std::endl;
    else
        std::cout << "ClapTrap named " << this->getName() << " has been destroyed" << std::endl;
}

unsigned int ClapTrap::getHitPoints(void) const
{
    return (_hitPoints);
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
    return (_energyPoints);
}

unsigned int ClapTrap::getAttackDamage(void) const
{
    return (_attackDamage);
}

std::string ClapTrap::getName(void) const
{
    return (_name);
}

void    ClapTrap::setHitPoints(const unsigned int hitPoints)
{
    _hitPoints = hitPoints;
}

void    ClapTrap::setEnergyPoints(const unsigned int energyPoints)
{
    _energyPoints = energyPoints;
}

bool    ClapTrap::checkAbility() const
{
    if (this->getHitPoints() <= 0)
    {
        std::cout << "ClapTrap " << this->getName() 
        << " is incapacitated and cannot take action!" << std::endl;
        return (false);
    }
    else if (this->getEnergyPoints() <= 0)
    {
        std::cout << "ClapTrap " << this->getName() 
        << " is out of energy and cannot take action!" << std::endl;
        return (false);
    }
    return (true);
}

void    ClapTrap::attack(const std::string& target)
{
    if (!ClapTrap::checkAbility())
        return ;
    std::cout << "ClapTrap " << this->getName() << " attacks " 
    << target << ", causing " << this->getAttackDamage() 
    << " points of damage!" << std::endl;
    this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->getHitPoints() <= 0)
    {
        std::cout << "ClapTrap " << this->getName() 
        << " is incapacitated and cannot take any more damage!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->getName() << " takes " 
    << amount << " points of damage!" << std::endl;
    if (this->getHitPoints() > amount)
        this->setHitPoints(this->getHitPoints() - amount);
    else
        this->setHitPoints(0);
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (!ClapTrap::checkAbility())
        return ;
    if (this->getHitPoints() + amount < 100)
    {
        std::cout << "ClapTrap " << this->getName() << " repairs itself, gaining " 
        << amount << " hit points!" << std::endl;
        this->setHitPoints(this->getHitPoints() + amount);
    }
    else
    {
        std::cout << "ClapTrap " << this->getName() 
        << " repairs itself, gaining maximum health!" << std::endl;
        setHitPoints(100);
    }
    this->setEnergyPoints(this->getEnergyPoints() - 1);
}
