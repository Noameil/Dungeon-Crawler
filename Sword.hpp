/*  Noam Eilat : 322713025
    Amit Lachmann : 207448267   */

#pragma once
#include "Item.hpp"

class Sword : public Item
{
private:
public:
    Sword(std::string name, ItemType itemType = SWORD, int healthBonus = 0, int strengthBonus = 10, int defenseBonus = 5)
        : Item(name, itemType, healthBonus, strengthBonus, defenseBonus) {}
    ~Sword() {}
};