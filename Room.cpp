/*  Noam Eilat : 322713025
    Amit Lachmann : 207448267   */

#include <stdexcept>
#include "Room.hpp"

Room::Room(std::string name)
    : name(name), monster(nullptr), north(nullptr), south(nullptr), east(nullptr), west(nullptr)
{
    if (name.empty())
    {
        throw std::invalid_argument("Error : Room Name must not be empty");
    }
}

Room::~Room()
{
    if (!itemList.isEmpty())
        delete &itemList;
    if (this->monster)
        delete this->monster;
    if (this->north)
        delete this->north;
    if (this->south)
        delete this->south;
    if (this->east)
        delete this->east;
    if (this->west)
        delete this->west;
}
