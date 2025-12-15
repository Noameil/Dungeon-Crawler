/*  Noam Eilat : 322713025
    Amit Lachmann : 207448267   */

#pragma once
#include <string>

typedef enum weapons_e
{
    sword,
    wand,
    dagger,
    NA,
}weapons;

class Item
{
private:
    weapons weaponType;
    std::string name;
    int healthBonus;
    int strengthBonus;
    int defenseBonus;

public:
    // Constructors / Destructor
    Item(std::string name, int healthBonus, int strengthBonus, int defenseBonus);
    ~Item() {}

    // Getters / Setters
    inline virtual std::string getItemName() const {}
    inline virtual void setItemName(std::string newName) {}
    inline virtual int getItemHealthBonus() const {}
    inline virtual void setItemHealthBonus(int newHealth) {}
    inline virtual int getItemStrengthBonus() const {}
    inline virtual void setItemStrengthBonus(int newStrength) {}
    inline virtual int getItemDefenseBonus() const {}
    inline virtual void setItemDefenseBonus(int newDefense) {}
    inline virtual weapons getWeaponType() {return this->weaponType;}
};
