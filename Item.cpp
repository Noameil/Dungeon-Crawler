// Noam Eilat : 322713025

#include <stdexcept>
#include "Item.hpp"

Item::Item(std::string name, int healthBonus, int strengthBonus, int defenseBonus)
{
    if (name.empty())
    {
        throw std::invalid_argument("Error : Name must not be empty");
    }
    if (healthBonus <= 0)
    {
        throw std::invalid_argument("Error : Health must be at least 1");
    }
    if (strengthBonus <= 0)
    {
        throw std::invalid_argument("Error : Strength must be at least 0");
    }
    if (defenseBonus <= 0)
    {
        throw std::invalid_argument("Error : Defense must be at least 0");
    }
}