/*  Noam Eilat : 322713025
    Amit Lachmann : 207448267   */

#pragma once

#include "Character.hpp"

class Monster
{
private:
    std::string name;
    int health;
    int strength;
    int defense;

public:
    // Constructors / Destructor
    Monster(std::string name, int health, int strength, int defense);
    ~Monster() {};

    // Main Functions
    void attack(Character &target);
    bool isDefeated() const;

    inline std::string getMonsterName() const {}
    inline void setMonsterName(std::string newName) {}
    inline int getMonsterHealth() const {}
    inline void setMonsterHealth(int newHealth) {}
    inline int getMonsterStrength() const {}
    inline void setMonsterStrength(int newStrength) {}
    inline int getMonsterDefense() const {}
    inline void setMonsterDefense(int newDefense) {}
};
