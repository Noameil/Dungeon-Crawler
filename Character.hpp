/*  Noam Eilat : 322713025
    Amit Lachmann : 207448267   */
#pragma once

#include <string>
#include "Monster.hpp"
#include "Item.hpp"
#include "Room.hpp"

// class Monster;

class Character
{
private:
    Room *currentRoom;
    std::string name;
    int health;
    int strength;
    int defense;
    Item *inventory[2];

public:
    // Constructors / Destructor
    Character() {}
    Character(std::string name, int health, int strength, int defense);
    virtual ~Character() = 0; // Delete inventory?

    // Main Functions
    virtual void attack(Monster &target);
    // virtual void defend(int damage);
    virtual bool isAlive() const;
    virtual bool pickUp(Item *item) = 0;

    // Getters / Setters
    inline virtual std::string getCharacterName() const { return name; }
    // inline virtual void setCharacterName(std::string newName) {}
    inline virtual Room *getCurrentRoom() const { return currentRoom; }
    inline virtual void setCurrentRoom(Room *roomToEnter) { currentRoom = roomToEnter; }
    inline virtual int getCharacterHealth() const { return health; }
    inline virtual void setCharacterHealth(int newHealth) { health = newHealth; }
    inline virtual void addCharacterHealth(int amount) { health += amount; }
    inline virtual int getCharacterStrength() const { return strength; }
    inline virtual void setCharacterStrength(int newStrength) { strength = newStrength; }
    inline virtual void addCharacterStrength(int amount) { strength += amount; }
    inline virtual int getCharacterDefense() const { return defense; }
    inline virtual void setCharacterDefense(int newDefense) { defense = newDefense; }
    inline virtual void addCharacterDefense(int amount) { defense += amount; }
    inline virtual int getTotalWeaponStats()
    {
        if (!inventory[0])
        {
            throw std::invalid_argument("Error : No Weapon in getTotalWeaponStats");
        }
        return inventory[0]->getItemDefenseBonus() + inventory[0]->getItemHealthBonus() + inventory[0]->getItemStrengthBonus();
    }
    inline virtual int getTotalShieldStats()
    {
        if (!inventory[1])
        {
            throw std::invalid_argument("Error : No Shield in getTotalShieldStats");
        }
        return inventory[1]->getItemDefenseBonus() + inventory[1]->getItemHealthBonus() + inventory[1]->getItemStrengthBonus();
    }
    inline virtual int getWeaponBonusHealth()
    {
        if (!inventory[0])
        {
            throw std::invalid_argument("Error : No Weapon in getWeaponBonusHealth");
        }
        return inventory[0]->getItemHealthBonus();
    }
    inline virtual int getWeaponBonusStrength()
    {
        if (!inventory[0])
        {
            throw std::invalid_argument("Error : No Weapon in getWeaponBonusStrength");
        }
        return inventory[0]->getItemStrengthBonus();
    }
    inline virtual int getWeaponBonusDefense()
    {
        if (!inventory[0])
        {
            throw std::invalid_argument("Error : No Weapon in getWeaponBonusDefense");
        }
        return inventory[0]->getItemDefenseBonus();
    }
    inline virtual int getShieldBonusHealth()
    {
        if (!inventory[1])
        {
            throw std::invalid_argument("Error : No Shield in getShieldBonusHealth");
        }
        return inventory[1]->getItemHealthBonus();
    }
    inline virtual int getShieldBonusStrength()
    {
        if (!inventory[1])
        {
            throw std::invalid_argument("Error : No Shield in getShieldBonusStrength");
        }
        return inventory[1]->getItemStrengthBonus();
    }
    inline virtual int getShieldBonusDefense()
    {
        if (!inventory[1])
        {
            throw std::invalid_argument("Error : No Shield in getShieldBonusDefense");
        }
        return inventory[1]->getItemDefenseBonus();
    }
    inline virtual void insertWeaponToInventory(Item *itemToAdd)
    {
        inventory[0] = itemToAdd;
        health += getWeaponBonusHealth();
        strength += getWeaponBonusStrength();
        defense += getWeaponBonusDefense();
    }
    inline virtual void insertShieldToInventory(Item *itemToAdd)
    {
        inventory[1] = itemToAdd;
        health += getShieldBonusHealth();
        strength += getShieldBonusStrength();
        defense += getShieldBonusDefense();
    }
    inline virtual void swapWeapon(Item *itemToAdd)
    {
        health -= getWeaponBonusHealth();
        strength -= getWeaponBonusStrength();
        defense -= getWeaponBonusDefense();
        insertWeaponToInventory(itemToAdd);
    }
    inline virtual void swapShield(Item *itemToAdd)
    {
        health -= getShieldBonusHealth();
        strength -= getShieldBonusStrength();
        defense -= getShieldBonusDefense();
        insertShieldToInventory(itemToAdd);
    }
    inline virtual Item *getFirstItem() { return inventory[0]; }
    inline virtual Item *getSecondItem() { return inventory[1]; }

    inline virtual void drinkPotion(Item *potion)
    {
        health += potion->getItemHealthBonus();
        defense += potion->getItemDefenseBonus();
        strength += potion->getItemStrengthBonus();
    }

    // Operators
    // virtual Character operator+(const Item &item);
};
