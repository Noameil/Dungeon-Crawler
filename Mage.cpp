// Noam Eilat : 322713025
// Amit Lachmann : 207448267

#include <stdexcept>
#include "Character.hpp"
#include "Mage.hpp"
#include "Item.hpp"

bool Mage::pickUp(Item *itemToAdd)
{
    ItemType type = itemToAdd->getItemType();
    switch (type)
    {
    case WAND:
    {
        int NewTotalStats = itemToAdd->getItemDefenseBonus() + itemToAdd->getItemHealthBonus() + itemToAdd->getItemStrengthBonus();
        int CurrTotalStats = this->getTotalWeaponStats();
        if (NewTotalStats > CurrTotalStats)
        {
            Character::swapWeapon(itemToAdd);
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