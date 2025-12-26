/*  Noam Eilat : 322713025
    Amit Lachmann : 207448267   */

#include <stdexcept>
#include "Character.hpp"

Character::Character(std::string name, int health, int strength, int defense)
    : name(name), health(health), strength(strength), defense(defense)
{
    if (name.empty())
    {
        throw std::invalid_argument("Error : Character Name must not be empty");
    }
    if (health <= 0)
    {
        throw std::invalid_argument("Error : Character Health must be at least 1");
    }
    if (strength <= 0)
    {
        throw std::invalid_argument("Error : Character Strength must be at least 0");
    }
    if (defense <= 0)
    {
        throw std::invalid_argument("Error : Character Defense must be at least 0");
    }
}

Character::~Character() {}

void Character::attack(Monster &target)
{
    target.setMonsterHealth(target.getMonsterHealth() - (this->strength - target.getMonsterDefense()));
}

void Character::swapWeapon(Item *itemToAdd)
{
    health -= getWeaponBonusHealth();
    strength -= getWeaponBonusStrength();
    defense -= getWeaponBonusDefense();
    insertWeaponToInventory(itemToAdd);
    health += getWeaponBonusHealth();
    strength += getWeaponBonusStrength();
    defense += getWeaponBonusDefense();
}
void Character::swapShield(Item *itemToAdd)
{
    health -= getShieldBonusHealth();
    strength -= getShieldBonusStrength();
    defense -= getShieldBonusDefense();
    insertShieldToInventory(itemToAdd);
    health += getShieldBonusHealth();
    strength += getShieldBonusStrength();
    defense += getShieldBonusDefense();
}

bool Character::isAlive() const
{
    return this->health > 0 ? true : false;
}
