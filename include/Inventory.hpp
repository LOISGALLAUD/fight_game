#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#define MAX_ITEMS 10
#define MAX_WEAPONS 1

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
    std::vector<Item *> getItems() const { return items; }
    Item *getItem(int index) const { return items[index]; }
    Weapon *getWeapon() const { return weapons[0]; }
    size_t getMaxItems() const { return maxItems; }
    size_t getMaxWeapons() const { return maxWeapons; }

    // Setters
    void setItems(std::vector<Item *> items) { this->items = items; }
    void setItem(int index, Item *item_ptr) { items[index] = item_ptr; }

    // Deleters
    void deleteItem(int index);
    void deleteWeapon();

    // Methods
    void display() const;
    template <typename T>
    void displayVector(const std::vector<T *> &items,
                       const std::string &type) const
    {
        std::cout << "->" << type << " :" << std::endl;
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
    void displayItems() const { displayVector(items, "items"); }
    void displayWeapons() const { displayVector(weapons, "weapon"); }

    template <typename T>
    void addItemToVector(T *item_ptr, std::vector<T *> &target_vector,
                         size_t max_items)
    {
        if (target_vector.size() < max_items)
        {
            // Créer un nouvel espace mémoire pour l'objet
            T *item = new T(*item_ptr);
            target_vector.push_back(item);
        }
        else
        {
            std::cout << "Inventory is full." << std::endl;
        }
    }
    void addItem(Item *item_ptr) { addItemToVector(item_ptr, items, maxItems); }
    void addWeapon(Weapon *weapon_ptr)
    {
        addItemToVector(weapon_ptr, weapons, maxWeapons);
    }

    // Booleans
    bool isFull() const { return items.size() == maxItems; }
    bool isEmpty() const { return items.size() == 0; }
    bool hasItem(int index) const { return items.size() > index; }
    bool hasWeapon() const { return weapons.size() > 0; }

  private:
    size_t maxItems = MAX_ITEMS;
    size_t maxWeapons = MAX_WEAPONS;
    std::vector<Item *> items;
    std::vector<Weapon *> weapons;
};
#endif
