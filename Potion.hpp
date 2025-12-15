/*  Noam Eilat : 322713025
    Amit Lachmann : 207448267   */

#pragma once
#include "Item.hpp"

class Potion : public Item
{
private:
public:
    Potion(std::string name, int potionHealthBonus, int potionStrengthBonus, int potionDefenseBonus, ItemType itemType = POTION)
        : Item(name, itemType, potionHealthBonus, potionStrengthBonus, potionDefenseBonus),
          potionHealthBonus(healthBonus), potionHealthBonus(strengthBonus), potionDefenseBonus(defenseBonus) {}
    ~Potion() {}
};