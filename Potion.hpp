// Noam Eilat : 322713025
// Amit Lachmann : 207448267

#pragma once
#include "Item.hpp"

typedef enum PotionType_e
{
    HEALTHP,
    STRENGTHP,
    DEFENSEP,
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
            potionType = STRENGTHP;
        }
        else if (type == "Health")
        {
            potionType = HEALTHP;
        }
        else if (type == "Defense")
        {
            potionType = DEFENSEP;
        }

        switch (this->potionType)
        {
        case HEALTHP:
            this->addItemHealthBonus(10);
            break;

        case STRENGTHP:
            this->addItemStrengthBonus(5);
            break;

        case DEFENSEP:
            this->addItemDefenseBonus(5);
            break;

        default:
            break;
        }
    }
    ~Potion() {}

    inline PotionType getPotionType()
    {
        return potionType;
    }
};