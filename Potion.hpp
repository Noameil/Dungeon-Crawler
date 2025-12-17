// Noam Eilat : 322713025
// Amit Lachmann : 207448267

#pragma once
#include "Item.hpp"

typedef enum PotionType_e
{
    HEALTH,
    STRENGTH,
    DEFENSE
} PotionType;

class Potion : public Item
{
private:
    PotionType potionType;

public:
    Potion(std::string name, PotionType potionType, int healthBonus, int strengthBonus, int defenseBonus, ItemType itemType = POTION)
        : Item(name, itemType, healthBonus, strengthBonus, defenseBonus)
    {
        switch (this->potionType)
        {
        case HEALTH:
            this->setItemHealthBonus(10);
            this->setItemStrengthBonus(0);
            this->setItemDefenseBonus(0);
            break;

        case STRENGTH:
            this->setItemHealthBonus(0);
            this->setItemStrengthBonus(5);
            this->setItemDefenseBonus(0);
            break;

        case DEFENSE:
            this->setItemHealthBonus(0);
            this->setItemStrengthBonus(0);
            this->setItemDefenseBonus(5);
            break;

        default:
            this->setItemHealthBonus(0);
            this->setItemStrengthBonus(0);
            this->setItemDefenseBonus(0);
            break;
        }
    }
    ~Potion() {}
};