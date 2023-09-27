#include "../include/Knight.hpp"
#include <iostream>

void Knight::attack(Character &target)
{
    std::cout << "Knight " << name << " attacks " << target.getName()
              << std::endl;
    target.receiveDamage(strength);
}
