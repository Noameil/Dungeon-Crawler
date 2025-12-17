// Noam Eilat : 322713025
// Amit Lachmann : 207448267

#include <stdexcept>
#include "Character.hpp"
#include "Thief.hpp"
#include "Item.hpp"

bool Thief::pickUp(Item* itemToAdd)
{
    ItemType type = itemToAdd->getItemType();
    switch (type)
    {
    case DAGGER:
        int NewTotalStats = itemToAdd->getItemDefenseBonus() + itemToAdd->getItemHealthBonus() + itemToAdd->getItemStrengthBonus();
        int CurrTotalStats = getTotalWeaponStats();
        if (NewTotalStats>CurrTotalStats)
        {
            Character::swapWeapon(itemToAdd);
        }
        return true; 
        break;
    case POTION:
        Character::drinkPotion(itemToAdd);
        return true;
        break;
        
    default:
        return false;
        break;
    }
}