#include "../include/Armor.hpp"

void Armor::display()
{
    std::cout << "Armor: " << name << std::endl;
    std::cout << "Rarity: " << rarity << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Defense: " << defense << std::endl;
    std::cout << std::endl;
}
