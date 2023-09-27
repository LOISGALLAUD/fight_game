#include "../include/Wizard.hpp"
#include <iostream>

void Wizard::attack(Character &target)
{
    std::cout << "Wizard " << name << " attacks " << target.getName()
              << std::endl;
    target.receiveDamage(strength);
}
