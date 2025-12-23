// Noam Eilat : 322713025
// Amit Lachmann : 207448267

#pragma once
#include "Item.hpp"

class Wand : public Item
{
private:
    ItemType item = WAND;
public:
    Wand(int healthBonus, int strengthBonus, int defenseBonus)
        : Item(0 + healthBonus, 10 + strengthBonus, 0 + defenseBonus) {}
    ~Wand() {}
};