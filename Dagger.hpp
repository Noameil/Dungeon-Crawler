// Noam Eilat : 322713025
// Amit Lachmann : 207448267

#pragma once
#include "Item.hpp"

class Dagger : public Item
{
private:
    ItemType item = DAGGER;
public:
    Dagger(int healthBonus, int strengthBonus, int defenseBonus)
        : Item(0 + healthBonus, 7 + strengthBonus, 3 + defenseBonus) {}
    ~Dagger() {}
};