#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#define MAX_ITEMS 10

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
    int getMoney() const { return money; }
    Item *getItem(int index) const { return items[index]; }
    Weapon *getWeapon() const { return weapon; }
    size_t getMaxItems() const { return maxItems; }

    // Setters
    void setMoney(int money) { this->money = money; }

    // Deleters
    void deleteItem(int index);
    void deleteWeapon();

    // Methods
    void display() const;
    void displayMoney() const;
    void displayItems() const;
    void displayWeapons() const;
    // void chooseItem() const;
    Weapon *chooseWeapon() const;
    void addItem(Item *item_ptr);
    void addWeapon(Weapon *weapon_ptr);

    // Booleans
    bool isFull() const { return items.size() == maxItems; }
    bool isEmpty() const { return items.size() == 0; }
    bool hasItem(int index) const { return items.size() > index; }
    bool hasWeapon() const { return weapon != nullptr; }

  private:
    int money = 0;
    size_t maxItems = MAX_ITEMS;
    std::vector<Item *> items;
    Weapon *weapon = nullptr;
};
#endif
