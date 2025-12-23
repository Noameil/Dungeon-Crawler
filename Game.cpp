#include "Game.hpp"

void Game::move(Directions whereToMove)
{
    Room *newRoom = currentRoom->getConnectedRoom(whereToMove);
    if (newRoom)
    {
        currentRoom = currentRoom->getConnectedRoom(whereToMove);
        return;
    }
    std::cout << "The is no room at the requested direction" << std::endl;
}

void Game::loadFromFile(std::string fileName)
{
    if (fileName.empty())
    {
        throw std::invalid_argument("Error : Invalid file name");
    }
    inputFile = std::ifstream(fileName);
    if (!inputFile)
    {
        throw std::runtime_error("Error : Couldn't open file");
    }
}

void Game::executeCommands()
{
    std::string line, arg;
    size_t posStart;
    size_t posEnd;

    while (getline(inputFile, line))
    {
        if (line.empty() || line.find("//") == 0)
            continue;

        std::stringstream streamString(line);
        streamString >> arg;
        if (arg == "Create")
        {
            handleCreate(streamString);
        }
        else if (arg == "Set")
        {
            handleSet(streamString);
        }
        else if (arg == "Connect")
        {
            handleConnect(streamString);
        }
        else if (arg == "Place")
        {
            handlePlace(streamString);
        }
        else if (arg == "Enter")
        {
            handleEnter(streamString);
        }
        else if (arg == "Move")
        {
            handleMove(streamString);
        }
        else if (arg == "Fight")
        {
            handleFight(streamString);
        }
        else if (arg == "PickUp")
        {
            handlePickUp(streamString);
        }
        else
        {
            throw std::invalid_argument("Error : Invalid input from file");
        }
    }
}

void Game::fight(Monster &foulBeing)
{
    while (player->getCharacterHealth() > 0 && foulBeing.getMonsterHealth() > 0)
    {
        player->attack(foulBeing);
        if (foulBeing.getMonsterHealth() > 0)
        {
            foulBeing.attack(*player);
        }
    }
}

void Game::handleCreate(std::stringstream &ss)
{
}

void Game::handleSet(std::stringstream &ss)
{
}

void Game::handleConnect(std::stringstream &ss)
{
}

void Game::handlePlace(std::stringstream &ss)
{
}

void Game::handleEnter(std::stringstream &ss)
{
}

void Game::handleMove(std::stringstream &ss)
{
}

void Game::handleFight(std::stringstream &ss)
{
}

void Game::handlePickUp(std::stringstream &ss)
{
}
