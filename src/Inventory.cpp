#include "../include/Inventory.hpp"

Inventory::~Inventory()
{
    for (auto item_ptr : items)
    {
        delete item_ptr;
    }
    items.clear();
}

void Inventory::displayItems() const
{
    std::cout << "-> Items:" << std::endl;
    if (items.size() == 0)
    {
        std::cout << "\t/!\\ Empty /!\\" << std::endl;
        return;
    }
    for (auto item : items)
    {
        std::cout << "\t-" << item->getName() << std::endl;
    }
}

void Inventory::displayWeapons() const
{
    std::cout << "-> Weapons:" << std::endl;
    if (weapon == nullptr)
    {
        std::cout << "\t/!\\ Empty /!\\" << std::endl;
        return;
    }
    std::cout << "\t-" << weapon->getName() << std::endl;
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
        delete weapon;
        weapon = nullptr;
    }
}

void Inventory::display() const
{
    displayItems();
    displayWeapons();
}

void Inventory::addItem(Item *item_ptr)
{
    if (items.size() < maxItems)
    {
        // Créer un nouvel espace mémoire pour l'objet
        Item *item = new Item(*item_ptr);
        items.push_back(item);
    }
    else
    {
        std::cout << "Inventory is full." << std::endl;
    }
}

void Inventory::addWeapon(Weapon *weapon_ptr)
{
    if (weapon == nullptr)
    {
        weapon = new Weapon(*weapon_ptr);
    }
    else
    {
        std::cout << "Inventory already has a weapon." << std::endl;
    }
}
