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
    Inventory getInventory() const { return inventory; }

    // Setters
    void setName(std::string name) { this->name = name; }
    void setHealth(int health) { this->health = health; }
    void setStrength(int strength) { this->strength = strength; }

    // Operators
    friend std::ostream &operator<<(std::ostream &os,
                                    const Character &character);

    // Methods
    void displayInventory() const;
    void receiveDamage(int damage);
    virtual void attack(Character &target) = 0; // Pure virtual method
    void collect(Item *item_ptr);
    void drop(int index);
    void equip(Weapon *weapon_ptr);
    void unequip();
    void use(Consumable *consumable_ptr);

    // Booleans
    bool isAlive() const { return health > 0; }
    bool hasWeapon() const { return inventory.hasWeapon(); }

  protected: // Protected attributes are accessible by derived classes
    std::string name;
    int health = 0;
    int strength = 0;
    Inventory inventory;
};

#endif
