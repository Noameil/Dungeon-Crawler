// Noam Eilat : 322713025

#pragma once
#include "Item.hpp"

class Sword : public Item
{
private:
public:
    Sword(std::string name, int health, int strength, int defense)
        : Item(name, health, strength, defense) {}
    ~Sword() {}
};