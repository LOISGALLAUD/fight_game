#ifndef WIZARD_HPP
#define WIZARD_HPP
#include "Character.hpp"
#include <iostream>
#include <string>
class Wizard : public Character
{
  public:
    // Constructor & Destructor
    ~Wizard() = default;
    Wizard(std::string name) : Character(name, 80, 50) {}
    void attack(Character &target) override;
};
#endif
