#ifndef WEAPON_HPP
#define WEAPON_HPP
#include "Item.hpp"
#include <string>
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

    // Methods
    void displayInfo();

  private:
    int damage = 0;
};
#endif
