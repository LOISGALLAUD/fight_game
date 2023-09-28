#ifndef ITEM_HPP
#define ITEM_HPP
#include <iostream>
#include <string>
class Item
{
  public:
    // Constructor & Destructor
    ~Item() = default;
    Item(std::string name, size_t rarity, int price)
        : name(name), rarity(rarity), price(price){};

    // Getters
    std::string getType() const { return "Item"; };
    std::string getName() const { return name; };
    size_t getRarity() const { return rarity; };
    int getPrice() const { return price; };

    // Setters
    void setName(std::string name) { this->name = name; };
    void setRarity(size_t rarity) { this->rarity = rarity; };
    void setPrice(int price) { this->price = price; };

    // Operators
    friend std::ostream &operator<<(std::ostream &os, const Item &item);

    // Methods
    void display();

  protected:
    std::string name;
    size_t rarity = 0;
    int price = 0;
};
#endif
