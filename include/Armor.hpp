#ifndef ARMOR_HPP
#define ARMOR_HPP

#include "Item.hpp"

class Armor : public Item
{
  public:
    // Constructor & Destructor
    ~Armor() = default;
    Armor(std::string name, size_t rarity, int price, int defense)
        : Item(name, rarity, price), defense(defense){};

    // Getters
    int getDefense() const { return defense; };

    // Setters
    void setDefense(int defense) { this->defense = defense; };

  private:
    int defense = 0;
};
#endif
