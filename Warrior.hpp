// Noam Eilat : 322713025

#pragma once
#include "Character.hpp"

class Warrior : public Character
{
private:
public:
    Warrior(std::string name, int health, int strength, int defense)
        : Character(name, health, strength, defense) {}
    ~Warrior() {}
};
