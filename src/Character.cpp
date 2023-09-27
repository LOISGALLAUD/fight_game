#include "../include/Character.hpp"
#include <iostream>

Character::Character(std::string name, int health, int strength)
    : name(name), health(health), strength(strength)
{
    this->displayInfo();
}

void Character::displayInfo() const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "HP: " << health << std::endl;
    std::cout << "Strength: " << strength << std::endl;
    std::cout << std::endl;
}

void Character::displayInventory() const
{
    std::cout << name << "'s inventory:" << std::endl;
    inventory.display();
    std::cout << std::endl;
}

void Character::receiveDamage(int damage)
{
    health -= damage;
    if (this->isAlive())
        std::cout << name << " received " << damage << " damage." << std::endl;
    else
        std::cout << name << " died." << std::endl;
}

void Character::collect(Item *item_ptr)
{
    if (!inventory.isFull())
    {
        inventory.addItem(item_ptr);
        std::cout << name << " collected " << item_ptr->getName() << std::endl;
    }
    else
        std::cout << name << " couldn't collect " << item_ptr->getName()
                  << std::endl;
}

void Character::drop(int index)
{
    if (inventory.hasItem(index))
    {
        inventory.deleteItem(index);
        std::cout << name << " dropped item." << std::endl;
    }
    else
        std::cout << name << " couldn't drop item." << std::endl;
}

void Character::equip(Weapon *weapon_ptr)
{
    if (!inventory.hasWeapon())
    {
        inventory.addWeapon(weapon_ptr);
        // Add Strength
        strength += weapon_ptr->getDamage();
        std::cout << name << " equipped " << weapon_ptr->getName() << std::endl;
    }
    else
        std::cout << name << " couldn't equip " << weapon_ptr->getName()
                  << std::endl;
}

void Character::unequip()
{
    if (inventory.hasWeapon())
    {
        // Remove Strength
        strength -= inventory.getWeapon()->getDamage();
        inventory.deleteWeapon();
        std::cout << name << " unequipped weapon." << std::endl;
    }
    else
        std::cout << name << " couldn't unequip weapon." << std::endl;
}
