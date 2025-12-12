// Noam Eilat : 322713025

#pragma once
#include "Item.hpp"

class Shield : public Item
{
private:
public:
    Shield(std::string name, int health, int strength, int defense)
        : Item(name, health, strength, defense) {}
    ~Shield() {}
};