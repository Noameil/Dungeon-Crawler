// Noam Eilat : 322713025
// Amit Lachmann : 207448267

#pragma once
#include "Item.hpp"

class Shield : public Item
{
private:
public:
    Shield(std::string name, ItemType itemType = SHIELD, int healthBonus = 0, int strengthBonus = 0, int defenseBonus = 5)
        : Item(name, itemType, healthBonus, strengthBonus, defenseBonus) {}
    ~Shield() {}
};