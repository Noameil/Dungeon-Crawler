/*  Noam Eilat : 322713025
    Amit Lachmann : 207448267   */
#pragma once

#include <string>
#include "Monster.hpp"
#include "Item.hpp"

class Character
{
private:
    std::string name;
    int health;
    int strength;
    int defense;
    Item inventory[2];

public:
    // Constructors / Destructor
    Character(std::string name, int health, int strength, int defense);
    virtual ~Character() = 0;

    // Main Functions
    virtual void attack(Monster &target);
    virtual void defend(int damage);
    virtual bool isAlive() const;
    virtual bool pickUp(Item item);

    // Getters / Setters
    inline virtual std::string getCharacterName() const {}
    inline virtual void setCharacterName(std::string newName) {}
    inline virtual int getCharacterHealth() const {}
    inline virtual void setCharacterHealth(int newHealth) {}
    inline virtual int getCharacterStrength() const {}
    inline virtual void setCharacterStrength(int newStrength) {}
    inline virtual int getCharacterDefense() const {}
    inline virtual void setCharacterDefense(int newDefense) {}

    // Operators
    virtual Character operator+(const Item &item);
};
