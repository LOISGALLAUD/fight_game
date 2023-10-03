#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Inventory.hpp"
#include "Item.hpp"
#include <string>

class Character
{
  public:
    // Constructor & Destructor
    ~Character() = default;
    Character(std::string name, int health, int strength);

    // Getters
    std::string getName() const { return name; }
    int getHealth() const { return health; }
    int getStrength() const { return strength; }
    // int getDamage() const { return strength + inventory.getDamage(); }
    int getMoney() const { return inventory.getMoney(); }

    // Setters
    void setHealth(int health) { this->health = health; }
    void setStrength(int strength) { this->strength = strength; }

    // Operators
    friend std::ostream &operator<<(std::ostream &os,
                                    const Character &character);

    // Methods
    // Display
    void display() const;
    void displayInventory() const;
    // Health
    void receiveDamage(int damage);
    // Attack
    virtual void attack(Character &target) = 0; // Pure virtual method
    // Inventory
    // Items
    void collect(Item *item_ptr);
    void drop(int index);
    // Weapons
    void equip(Weapon *weapon_ptr);
    void unequip();
    // Consumables
    void use(Consumable *consumable_ptr);
    // Choose
    Weapon *chooseWeapon() const { return inventory.chooseWeapon(); }
    // Money
    // void addMoney(int amount) { inventory.addMoney(amount); }
    // void removeMoney(int amount) { inventory.removeMoney(amount); }

    // Booleans
    bool isAlive() const { return health > 0; }
    bool hasWeapon() const { return inventory.hasWeapon(); }
    bool isInventoryEmpty() const { return inventory.isEmpty(); }

  protected: // Protected attributes are accessible by derived classes
    std::string name;
    int health = 0;
    int strength = 0;
    Inventory inventory;
};

#endif
