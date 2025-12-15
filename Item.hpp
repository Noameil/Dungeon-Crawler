// Noam Eilat : 322713025
// Amit Lachmann : 207448267

#pragma once
#include <string>

typedef enum ItemType_e
{
    SWORD,
    WAND,
    DAGGER,
    SHIELD,
    POTION,
} ItemType;

class Item
{
private:
    std::string name;
    ItemType itemType;
    int healthBonus;
    int strengthBonus;
    int defenseBonus;

public:
    // Constructors / Destructor
    Item(std::string name, ItemType itemType, int healthBonus, int strengthBonus, int defenseBonus);
    virtual ~Item() = 0;

    // Getters / Setters
    inline virtual ItemType getItemType() { return this->itemType; }
    inline virtual std::string getItemName() const { return this->name; }
    inline virtual void setItemName(std::string newName) {}
    inline virtual int getItemHealthBonus() const { return this->healthBonus; }
    inline virtual void setItemHealthBonus(int newHealth) {}
    inline virtual int getItemStrengthBonus() const { return this->strengthBonus; }
    inline virtual void setItemStrengthBonus(int newStrength) {}
    inline virtual int getItemDefenseBonus() const { return this->defenseBonus; }
    inline virtual void setItemDefenseBonus(int newDefense) {}
};
