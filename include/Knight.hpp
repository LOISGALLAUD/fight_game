#ifndef KNIGHT_HPP
#define KNIGHT_HPP
#include "Character.hpp"
#include <iostream>
#include <string>
class Knight : public Character
{
  public:
    // Constructor & Destructor
    ~Knight() = default;
    Knight(std::string name) : Character(name, 100, 40){};
    void attack(Character &target) override;
};
#endif
