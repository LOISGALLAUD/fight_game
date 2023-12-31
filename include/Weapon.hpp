#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "Item.hpp"

class Weapon : public Item
{
  public:
    // Constructor & Destructor
    ~Weapon() = default;
    Weapon(std::string name, size_t rarity, int price, int damage)
        : Item(name, rarity, price), damage(damage){};

    // Getters
    int getDamage() const { return damage; };

    // Setters
    void setDamage(int damage) { this->damage = damage; };

    // Operators
    // friend std::ostream &operator<<(std::ostream &os, const Weapon &weapon);

    // Methods
    void display();

  private:
    int damage = 0;
};
#endif
