#include "../include/Consumable.hpp"

void Consumable::display()
{
    std::cout << "Consumable: " << name << std::endl;
    std::cout << "Rarity: " << rarity << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Health Bonus: " << healthBonus << std::endl;
    std::cout << std::endl;
}
