#include "../include/Character.hpp"
#include <iostream>

Character::Character(std::string name, int health, int strength)
    : name(name), health(health), strength(strength)
{
    std::cout << "-> Character created." << std::endl;
    std::cout << *this;
}

std::ostream &operator<<(std::ostream &os, const Character &character)
{
    os << "Name: " << character.name << std::endl;
    os << "HP: " << character.health << std::endl;
    os << "Strength: " << character.strength << std::endl;
    os << std::endl;
    return os;
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
        strength += weapon_ptr->getDamage(); // Add Strength
        std::cout << name << " equipped " << weapon_ptr->getName() << " (+"
                  << weapon_ptr->getDamage() << " Strength)" << std::endl;
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

void Character::use(Consumable *consumable_ptr)
{
    // Add Health
    health += consumable_ptr->getHealthBonus();
    std::cout << name << " used " << consumable_ptr->getName() << " (+"
              << consumable_ptr->getHealthBonus() << " HP)" << std::endl;
}

void Character::pay(Character &target, int amount)
{
    if (inventory.getMoney() >= amount)
    {
        inventory.removeMoney(amount);
        target.inventory.addMoney(amount);
        std::cout << name << " paid " << amount << " to " << target.name
                  << std::endl;
    }
    else
        std::cout << name << " couldn't pay " << amount << " to " << target.name
                  << std::endl;
}
