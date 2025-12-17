// Noam Eilat : 322713025
// Amit Lachmann : 207448267

#include <stdexcept>
#include "Item.hpp"

Item::Item(std::string name, ItemType itemType, int healthBonus, int strengthBonus, int defenseBonus)
{
    if (name.empty())
    {
        throw std::invalid_argument("Error : Name must not be empty");
    }
}
