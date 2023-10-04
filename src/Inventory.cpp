#include "../include/Inventory.hpp"

Inventory::~Inventory() { items.clear(); }

void Inventory::displayGold() const
{
    std::cout << "-> Gold: " << std::endl << "\t" << gold << std::endl;
}

int Inventory::getIndex(Item *item_ptr) const
{
    for (size_t i = 0; i < items.size(); i++)
    {
        if (items[i] == item_ptr)
        {
            return i;
        }
    }
    return -1;
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

void Inventory::displayWeapon() const
{
    std::cout << "-> Weapons:" << std::endl;
    if (weapon == nullptr)
    {
        std::cout << "\t/!\\ Empty /!\\" << std::endl;
        return;
    }
    std::cout << "\t-" << weapon->getName() << std::endl;
}

void Inventory::displayArmor() const
{
    std::cout << "-> Armor:" << std::endl;
    if (armor == nullptr)
    {
        std::cout << "\t/!\\ Empty /!\\" << std::endl;
        return;
    }
    std::cout << "\t-" << armor->getName() << std::endl;
}

Weapon *Inventory::chooseWeapon() const
{

    std::cout << "Choose a weapon:" << std::endl;
    for (size_t i = 0; i < items.size(); i++)
    {
        if (items[i]->isWeapon())
        {
            std::cout << "\t" << i << " - " << items[i]->getName() << std::endl;
        }
    }
    int choice;
    std::cin >> choice;
    while (choice < 0 || (choice >= items.size()) | !items[choice]->isWeapon())
    {
        std::cout << "Invalid choice, try again:" << std::endl;
        std::cin >> choice;
    }
    std::cout << "You chose " << items[choice]->getName() << std::endl;
    return dynamic_cast<Weapon *>(items[choice]);
}

void Inventory::deleteItem(int index)
{
    if (items[index] != nullptr)
    {
        items.erase(items.begin() + index);
    }
}

void Inventory::deleteWeapon()
{
    if (this->hasWeapon())
    {
        weapon = nullptr;
    }
}

void Inventory::deleteArmor()
{
    if (this->hasArmor())
    {
        armor = nullptr;
    }
}

void Inventory::display() const
{
    displayGold();
    displayItems();
    displayWeapon();
    displayArmor();
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
        std::cout << "Weapon slot is empty: equipping..." << std::endl;

        weapon = weapon_ptr;
    }
    else
    {
        std::cout << "Inventory already has a weapon." << std::endl;
    }
}

void Inventory::addArmor(Armor *armor_ptr)
{
    if (armor == nullptr)
    {
        std::cout << "Armor slot is empty: equipping..." << std::endl;
        armor = armor_ptr;
    }
    else
    {
        std::cout << "Inventory already has an armor." << std::endl;
    }
}
