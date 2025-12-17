// Noam Eilat : 322713025
// Amit Lachmann : 207448267

#pragma once
#include "Item.hpp"

class Dagger : public Item
{
private:
public:
    Dagger(std::string name, ItemType itemType = DAGGER, int healthBonus = 0, int strengthBonus = 7, int defenseBonus = 3)
        : Item(name, itemType, healthBonus, strengthBonus, defenseBonus) {}
    ~Dagger() {}
};