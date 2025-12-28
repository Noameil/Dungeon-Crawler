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
    case SHIELD:
    {
        int NewTotalStats = itemToAdd->getItemDefenseBonus() + itemToAdd->getItemHealthBonus() + itemToAdd->getItemStrengthBonus();
        if (getSecondItem() == nullptr)
        {
            insertShieldToInventory(itemToAdd);
        }
        else
        {
            int CurrTotalStats = getTotalShieldStats();
            if (NewTotalStats > CurrTotalStats)
            {
                Character::swapShield(itemToAdd);
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
