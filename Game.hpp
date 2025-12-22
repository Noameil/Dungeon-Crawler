// Noam Eilat : 322713025
// Amit Lachmann : 207448267

#pragma once

#include "Dungeon.hpp"

class Game
{
private:
    /* data */
public:
    Game();
    ~Game();
    void move(Directions whereToMove);
    FILE loadFromFile(std::string fileName);
    void executeCommands();
    void outputFinalState(std::string fileOutputName);
    void fight(Character *player, Monster *foulBeing);
    
};

Game::Game()
{
}

Game::~Game()
{
}
