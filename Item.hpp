// Noam Eilat : 322713025

#pragma once
#include <string>

class Item
{
private:
    std::string name;
    int healthBonus;
    int strengthBonus;
    int defenseBonus;

public:
    // Constructors / Destructor
    Item(std::string name, int healthBonus, int strengthBonus, int defenseBonus);
    ~Item() {}

    // Getters / Setters
    inline std::string getItemName() const {}
    inline void setItemName(std::string newName) {}
    inline int getItemHealthBonus() const {}
    inline void setItemHealthBonus(int newHealth) {}
    inline int getItemStrengthBonus() const {}
    inline void setItemStrengthBonus(int newStrength) {}
    inline int getItemDefenseBonus() const {}
    inline void setItemDefenseBonus(int newDefense) {}
};
