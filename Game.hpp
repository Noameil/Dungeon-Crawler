// Noam Eilat : 322713025
// Amit Lachmann : 207448267

#pragma once

#include "Dungeon.hpp"
#include "Character.hpp"
#include "Item.hpp"
#include "Monster.hpp"
#include <fstream>
#include <sstream>

typedef enum FightResult_E
{
    VICTORY,
    LOSE,
} FightResult;

class Game
{
private:
    Dungeon dungeon;
    Character *player;
    Room *currentRoom;
    std::ifstream inputFile;
    std::ofstream outputFile;

public:
    Game() {};
    ~Game() { delete player; }
    void move(Directions whereToMove);
    void loadFromFile(std::string fileName);
    void executeCommands();
    void outputFinalState(std::string fileOutputName);
    FightResult fight(Monster &foulBeing);

    void handleCreate(std::stringstream &ss);
    void handleSet(std::stringstream &ss);
    void handleConnect(std::stringstream &ss);
    void handlePlace(std::stringstream &ss);
    void handleEnter(std::stringstream &ss);
    void handleMove(std::stringstream &ss);
    void handleFight(std::stringstream &ss);
    void handlePickUp(std::stringstream &ss);
    void handlePlaceMonster(std::stringstream &ss);
    void handlePlaceItem(std::string arg2, std::stringstream &ss);
    void handlePotion(std::string arg2, std::stringstream &ss);

    inline Room *getCurrentRoom()
    {
        return currentRoom;
    }
};
