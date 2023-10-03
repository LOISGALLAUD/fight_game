#include "../include/Item.hpp"
#include <iostream>
#include <string>

bool Item::isWeapon() const
{
    std::string type = typeid(*this).name();
    return type.find("Weapon") != std::string::npos;
}
