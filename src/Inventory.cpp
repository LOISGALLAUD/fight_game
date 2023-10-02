#include "../include/Inventory.hpp"

Inventory::~Inventory()
{
    for (auto item_ptr : items)
    {
        delete item_ptr;
    }
    items.clear();
    delete weapon;
}

void Inventory::displayMoney() const
{
    std::cout << "-> Money: " << std::endl << "\t" << money << std::endl;
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

void Inventory::chooseItem() const
{
    if (items.size() != 0)
    {
        std::cout << "Choose an item:" << std::endl;
        for (size_t i = 0; i < items.size(); i++)
        {
            std::cout << "\t" << i << " - " << items[i]->getName() << std::endl;
        }
        int choice;
        std::cin >> choice;
        while (choice < 0 || choice >= items.size())
        {
            std::cout << "Invalid choice, try again:" << std::endl;
            std::cin >> choice;
        }
        std::cout << "You chose " << items[choice]->getName() << std::endl;
    }
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
    displayMoney();
    displayItems();
    displayWeapons();
}

void Inventory::addItem(Item *item_ptr)
{
    if (items.size() < maxItems)
    {
        items.push_back(item_ptr);
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
        Weapon *weapon = new Weapon(*weapon_ptr);
        this->weapon = weapon;
    }
    else
    {
        std::cout << "Inventory already has a weapon." << std::endl;
    }
}
