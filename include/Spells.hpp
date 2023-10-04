#ifndef SPELLS_HPP
#define SPELLS_HPP

#include <string>

class Spells
{
  public:
    // Constructor & Destructor
    ~Spells() = default;
    Spells(std::string name, int damage, int cost)
        : name(name), damage(damage), cost(cost){};

    // Getters
    std::string getName() const { return name; }
    int getDamage() const { return damage; }
    int getCost() const { return cost; }

    // Methods
    void display() const;

    // Booleans
    bool isUsable(int mana) const { return mana >= cost; }

  private:
    std::string name;
    int damage;
    int cost;
};
#endif
