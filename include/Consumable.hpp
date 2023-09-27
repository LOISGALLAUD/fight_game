#ifndef CONSUMABLE_HPP
#define CONSUMABLE_HPP

#include "Item.hpp"

class Consumable : public Item
{
  public:
    // Constructor & Destructor
    ~Consumable() = default;
    Consumable(std::string name, int weight, int value, int health)
        : Item(name, weight, value), healthBonus(health){};

    // Getters
    std::string getType() const { return "Consumable"; }
    int getHealthBonus() const { return healthBonus; }

    // Setters
    void setHealthBonus(int health) { this->healthBonus = health; }

    // Operators
    // friend std::ostream &operator<<(std::ostream &os, const Consumable
    // &consumable);

    // Methods
    void display() const;

  private:
    int healthBonus = 0;
};

#endif
