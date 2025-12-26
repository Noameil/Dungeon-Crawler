// Noam Eilat : 322713025
// Amit Lachmann : 207448267

#include <stdexcept>
#include "Character.hpp"
#include "Warrior.hpp"
#include "Item.hpp"

// Warrior::Warrior()
// {
//     setCharacterHealth(100);
//     setCharacterDefense(10);
//     setCharacterStrength(15);
// }

bool Warrior::pickUp(Item *itemToAdd)
{
    if (!itemToAdd)
    {
        throw std::invalid_argument("Error : null item in pickUp Warrior");
    }
    ItemType type = itemToAdd->getItemType();
    switch (type)
    {
    case SWORD:
    {
        int NewTotalStats = itemToAdd->getItemDefenseBonus() + itemToAdd->getItemHealthBonus() + itemToAdd->getItemStrengthBonus();
        int CurrTotalStats = getTotalWeaponStats();
        if (NewTotalStats > CurrTotalStats)
        {
            Character::swapWeapon(itemToAdd);
        }
        return true;
        break;
    }
    case SHIELD:
    {
        int NewTotalStats = itemToAdd->getItemDefenseBonus() + itemToAdd->getItemHealthBonus() + itemToAdd->getItemStrengthBonus();
        int CurrTotalStats = getTotalShieldStats();
        if (NewTotalStats > CurrTotalStats)
        {
            Character::swapShield(itemToAdd);
        }
        return true;
        break;
    }
    case POTION:
    {
        Character::drinkPotion(itemToAdd);
        return true;
        break;
    }

    default:
        return false;
        break;
    }
}