/*  Noam Eilat : 322713025
    Amit Lachmann : 207448267   */

#pragma once
#include "Character.hpp"

class Thief : public Character
{
private:
public:
    Thief(std::string name, int health, int strength, int defense)
        : Character(name, health, strength, defense) {}
    ~Thief() {}
    bool pickUp(Item* itemToAdd);
};