/*  Noam Eilat : 322713025
    Amit Lachmann : 207448267   */

#pragma once

#include <string>
#include "Item.hpp"
#include "Monster.hpp"

class Room
{
private:
    std::string name;
    Item *item;
    Monster *monster;
    Room *north;
    Room *south;
    Room *east;
    Room *west;

public:
    // Constructors / Destructor
    Room(std::string name);
    ~Room();

    // Getters / Setters
    inline std::string getName() const
    {
        return this->name;
    }
    inline void setName(std::string newName)
    {
        this->name = newName;
    }
    inline void setItem(Item *item)
    {
        this->item = item;
    }
    inline void setMonster(Monster *monster)
    {
        this->monster = monster;
    }
    inline void connectNorth(Room *room)
    {
        this->north = room;
    }
    inline void connectSouth(Room *room)
    {
        this->south = room;
    }
    inline void connectEast(Room *room)
    {
        this->east = room;
    }
    inline void connectWest(Room *room)
    {
        this->west = room;
    }
};
