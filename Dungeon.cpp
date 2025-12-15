/*  Noam Eilat : 322713025
    Amit Lachmann : 207448267   */
    
#include "Dungeon.hpp"

Dungeon::Dungeon() : startRoom(nullptr)
{
    this->rooms = new Room *[DUNGEON_SIZE];
}

Dungeon::~Dungeon()
{
    if (this->startRoom)
        delete startRoom;
    if (this->rooms)
    {
        for (int i = 0; i < DUNGEON_SIZE; i++)
        {
            if (this->rooms[i])
                delete this->rooms[i];
        }
        delete[] this->rooms;
    }
}
