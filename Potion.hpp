// Noam Eilat : 322713025

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