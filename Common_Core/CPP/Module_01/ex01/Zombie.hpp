#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    public:
        void    announce();
        Zombie(std::string name);
        Zombie();
        ~Zombie();
        void setName(std::string name);
    private:
        std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
