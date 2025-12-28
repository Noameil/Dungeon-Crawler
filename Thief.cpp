// Noam Eilat : 322713025
// Amit Lachmann : 207448267

#include <stdexcept>
#include "Character.hpp"
#include "Thief.hpp"
#include "Item.hpp"

bool Thief::pickUp(Item *itemToAdd)
{
    ItemType type = itemToAdd->getItemType();
    switch (type)
    {
    case DAGGER:
    {
        int NewTotalStats = itemToAdd->getItemDefenseBonus() + itemToAdd->getItemHealthBonus() + itemToAdd->getItemStrengthBonus();
        if (getFirstItem() == nullptr)
        {
            insertWeaponToInventory(itemToAdd);
        }
        else
        {
            int CurrTotalStats = getTotalWeaponStats();
            if (NewTotalStats > CurrTotalStats)
            {
                Character::swapWeapon(itemToAdd);
            }
        }
        std::cout << getCharacterName() << " has picked up the " << itemToAdd->getName() << std::endl;
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
    {
        std::cout << getCharacterName() << " can't pick up the " << itemToAdd->getName() << std::endl;
        return false;
        break;
    }
    }
}