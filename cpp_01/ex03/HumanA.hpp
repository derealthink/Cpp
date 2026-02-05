#ifndef HUMAN_A
#define HUMAN_A 

#include "Weapon.hpp"
#include <string>

class HumanA{
    private:
        Weapon &_weapon;
        std::string _name;
    public:
        HumanA(std::string TypeName, Weapon &TypeWeapon);
        void attack();
};


#endif