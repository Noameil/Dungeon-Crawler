// Noam Eilat : 322713025
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

public:
    // Constructors / Destructor
    Character(std::string name, int health, int strength, int defense);
    ~Character() {};

    // Main Functions
    void attack(Monster &target);
    void defend(int damage);
    bool isAlive() const;

    // Getters / Setters
    inline std::string getCharacterName() const {}
    inline void setCharacterName(std::string newName) {}
    inline int getCharacterHealth() const {}
    inline void setCharacterHealth(int newHealth) {}
    inline int getCharacterStrength() const {}
    inline void setCharacterStrength(int newStrength) {}
    inline int getCharacterDefense() const {}
    inline void setCharacterDefense(int newDefense) {}

    // Operators
    Character operator+(const Item &item);
};
