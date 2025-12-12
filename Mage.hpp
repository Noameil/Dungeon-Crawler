// Noam Eilat : 322713025

#pragma once
#include "Character.hpp"

class Mage : public Character
{
private:
public:
    Mage(std::string name, int health, int strength, int defense)
        : Character(name, health, strength, defense) {}
    ~Mage() {}
};