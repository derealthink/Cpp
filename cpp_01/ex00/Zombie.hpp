#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP


#include <iostream>
#include <string>


class Zombie
{

private :
    std::string name;

public :
    void announce(void)
    {
        std::cout << name << ": BraiiiiiiinnnzzzZ...\n";//this also has to be moved
    }
    
    Zombie(std::string zombieName)
    {
        name = zombieName;
    }

    ~Zombie() 
    {
        std::cout << name << "has been Destroyed\n";//these need to bemoved
    }
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);


#endif