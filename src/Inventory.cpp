#include "../include/Inventory.hpp"

Inventory::~Inventory()
{
    for (auto item_ptr : items)
    {
        delete item_ptr;
    }
    items.clear();
}

void Inventory::deleteItem(int index)
{
    if (items[index] != nullptr) // items[index] == items.at(index)
    {
        delete items[index];
        items.erase(items.begin() + index);
    }
}

void Inventory::deleteWeapon()
{
    if (this->hasWeapon())
    {
        delete weapons[0];
        weapons.clear();
    }
}

void Inventory::display() const
{
    displayItems();
    displayWeapons();
}
