#include <string>

class Zombie
{
    public:
        void    announce();
        static Zombie* newZombie(std::string name);
        static void    randomChump(std::string name);
        ~Zombie();
    private:
        Zombie(std::string name);
        std::string _name;
};
