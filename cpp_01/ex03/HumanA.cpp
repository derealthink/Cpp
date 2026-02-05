#include "HumanA.hpp"

HumanA::HumanA(std::string TypeName, Weapon &TypeWeapon) :
        _weapon(TypeWeapon), _name(TypeName) {
}

void HumanA::attack() {
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}