#include "../include/Golem.hpp"
#include <iostream>

void Golem ::attack(Character &target)
{
    std::cout << "Golem " << name << " attacks " << target.getName()
              << std::endl;
    target.receiveDamage(strength);
}
