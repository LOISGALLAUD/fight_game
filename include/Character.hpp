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
    float getTenacity() const { return tenacity; }
    int getStrength() const { return strength; }
    int getMana() const { return mana; }
    int getGold() const { return inventory.getGold(); }
    int getIndexOf(Item *item_ptr) const
    {
        return inventory.getIndex(item_ptr);
    }
    int getArmorDefense() const { return inventory.getDefense(); }

    // Setters
    void setHealth(int health) { this->health = health; }
    void setStrength(int strength) { this->strength = strength; }

    // Deleters
    void deleteItem(int index) { inventory.deleteItem(index); }

    // Operators
    friend std::ostream &operator<<(std::ostream &os,
                                    const Character &character);

    // Methods
    // Display
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
    void wear(Armor *armor_ptr);
    void unclothe();
    // Consumables
    void use(Consumable *consumable_ptr);
    // Choose
    Weapon *chooseWeapon() const { return inventory.chooseWeapon(); }
    // Gold
    void addGold(int amount) { inventory.addGold(amount); }
    void removeGold(int amount) { inventory.removeGold(amount); }
    void pay(Character &target, int amount);

    // Booleans
    bool isAlive() const { return health > 0; }
    bool hasWeapon() const { return inventory.hasWeapon(); }
    bool hasArmor() const { return inventory.hasArmor(); }
    bool isInventoryEmpty() const { return inventory.isEmpty(); }

  protected: // Protected attributes are accessible by derived classes
    std::string name;
    int health = 0;
    float tenacity = 0.85;
    int strength = 0;
    int mana = 0;
    Inventory inventory;
};

#endif
