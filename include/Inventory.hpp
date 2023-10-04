#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "Armor.hpp"
#include "Consumable.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>
#include <vector>
class Inventory
{
  public:
    // Constructor & Destructor
    ~Inventory();
    Inventory() = default;

    // Getters
    int getGold() const { return gold; }
    Item *getItem(int index) const { return items[index]; }
    Weapon *getWeapon() const { return weapon; }
    size_t getMaxItems() const { return maxItems; }

    // Setters
    void setGold(int gold) { gold = gold; }

    // Deleters
    void deleteItem(int index);
    void deleteWeapon();
    void deleteArmor();

    // Methods
    void display() const;
    void displayGold() const;
    void displayItems() const;
    void displayWeapons() const;
    // void chooseItem() const;
    Weapon *chooseWeapon() const;
    void addItem(Item *item_ptr);
    void addWeapon(Weapon *weapon_ptr);
    void addArmor(Armor *armor_ptr);
    // Gold
    void addGold(int amount) { gold += amount; }
    void removeGold(int amount) { gold -= amount; }

    // Booleans
    bool isFull() const { return items.size() == maxItems; }
    bool isEmpty() const { return items.size() == 0; }
    bool hasItem(int index) const { return items.size() > index; }
    bool hasWeapon() const { return weapon != nullptr; }
    bool hasArmor() const { return armor != nullptr; }

  private:
    int gold = 0;
    size_t maxItems = 10;
    std::vector<Item *> items;
    Weapon *weapon = nullptr;
    Armor *armor = nullptr;
};
#endif
