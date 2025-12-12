// Noam Eilat : 322713025

#pragma once

#include "Room.hpp"

#define DUNGEON_SIZE 5

class Dungeon
{
private:
    Room *startRoom;
    Room **rooms;

public:
    // Constructors / Destructor
    Dungeon();
    ~Dungeon();

    // Main Functions
    void addRoom(Room *room);
    Room *findRoom(std::string name);

    // Getters / Setters
    inline Room *getStartRoom() const
    {
        return this->startRoom;
    }
    inline void setStartRoom(Room *room)
    {
        this->startRoom = room;
    }
};
