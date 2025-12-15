/*  Noam Eilat : 322713025
    Amit Lachmann : 207448267   */

#pragma once
#include "Item.hpp"

class Potion : public Item
{
private:
public:
    Potion(std::string name, int health, int strength, int defense)
        : Item(name, health, strength, defense) {}
    ~Potion() {}
};