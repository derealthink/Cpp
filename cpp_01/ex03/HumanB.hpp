#ifndef HUMAN_B
#define HUMAN_B 

#include "Weapon.hpp"
#include <string>

class HumanB{
    private:
        Weapon *_weapon;
        std::string _name;
    public:
        explicit HumanB(std::string TypeName);
        void setWeapon(Weapon &TypeClub);
        void attack();
};


#endif