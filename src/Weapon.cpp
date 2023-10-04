#include "../include/Weapon.hpp"

void Weapon::display()
{
    std::cout << "Weapon: " << name << std::endl;
    std::cout << "Rarity: " << rarity << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Damage: " << damage << std::endl;
    std::cout << std::endl;
}
