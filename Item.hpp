// Noam Eilat : 322713025
// Amit Lachmann : 207448267

#pragma once
#include <string>
#include "Sword.hpp"
#include "Shield.hpp"
#include "Dagger.hpp"
#include "Wand.hpp"
#include "Potion.hpp"

typedef enum ItemType_e
{
    SWORD,
    WAND,
    DAGGER,
    SHIELD,
    POTION
} ItemType;

class Item
{
private:
    ItemType itemType;
    int healthBonus;
    int strengthBonus;
    int defenseBonus;

public:
    // Constructors / Destructor
    Item(int healthBonus, int strengthBonus, int defenseBonus);
    virtual ~Item() = 0;

    // Getters / Setters
    inline virtual ItemType getItemType() { return this->itemType; }
    inline virtual int getItemHealthBonus() const { return this->healthBonus; }
    inline virtual void setItemHealthBonus(int newHealth) {}
    inline virtual void addItemHealthBonus(int addHealth) {healthBonus += addHealth;}
    inline virtual int getItemStrengthBonus() const { return this->strengthBonus; }
    inline virtual void addItemStrengthBonus(int addStrength) {strengthBonus += addStrength;}
    inline virtual void setItemStrengthBonus(int newStrength) {}
    inline virtual int getItemDefenseBonus() const { return this->defenseBonus; }
    inline virtual void setItemDefenseBonus(int newDefense) {}
    inline virtual void addItemDefenseBonus(int addDefense) {defenseBonus += addDefense;}
};
