// Noam Eilat : 322713025

#pragma once
#include "Character.hpp"

class Thief : public Character
{
private:
public:
    Thief(std::string name, int health, int strength, int defense)
        : Character(name, health, strength, defense) {}
    ~Thief() {}
};