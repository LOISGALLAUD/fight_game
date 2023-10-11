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
    int getHealthBonus() const { return healthBonus; }

    // Setters
    void setHealthBonus(int health) { healthBonus = health; }

    // Operators
    friend std::ostream &operator<<(std::ostream &os,
                                    const Consumable &consumable);

    // Methods
    void display();

  private:
    int healthBonus = 0;
};

#endif
