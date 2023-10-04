#include "../include/Spells.hpp"
#include <iostream>

void Spells::display() const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Damage: " << damage << std::endl;
    std::cout << "Cost: " << cost << std::endl;
    std::cout << std::endl;
}
