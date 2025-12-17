// Noam Eilat : 322713025
// Amit Lachmann : 207448267

#pragma once
#include "Item.hpp"

class Wand : public Item
{
private:
public:
    Wand(std::string name, ItemType itemType = WAND, int healthBonus = 0, int strengthBonus = 10, int defenseBonus = 0)
        : Item(name, itemType, healthBonus, strengthBonus, defenseBonus) {}
    ~Wand() {}
};