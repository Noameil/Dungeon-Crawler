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
    ItemType item = POTION;
public:
    Potion(std::string type,int healthBonus, int strengthBonus, int defenseBonus)
        : Item(healthBonus, strengthBonus, defenseBonus)
    {
        if (type == "Strength")
        {
            potionType = STRENGTH;
        }
        else if (type == "Health")
        {
            potionType = HEALTH;
        }
        else if (type == "Defense")
        {
            potionType = DEFENSE;
        }

        switch (this->potionType)
        {
        case HEALTH:
            this->addItemHealthBonus(10);
            break;

        case STRENGTH:
            this->addItemStrengthBonus(5);
            break;

        case DEFENSE:
            this->addItemDefenseBonus(5);
            break;

        default:
            break;
        }
    }
    ~Potion() {}
};