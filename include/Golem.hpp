#ifndef GOLEM_HPP
#define GOLEM_HPP
#include "Character.hpp"
#include <iostream>
#include <string>
class Golem : public Character
{
  public:
    // Constructor & Destructor
    ~Golem() = default;
    Golem(std::string name) : Character(name, 200, 30){};
    void attack(Character &target) override;
};
#endif
