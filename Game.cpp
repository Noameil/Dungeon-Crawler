#include "Game.hpp"

using namespace std;

void Game::move(Directions whereToMove)
{
    Room *newRoom = currentRoom->getConnectedRoom(whereToMove);
    if (newRoom)
    {
        currentRoom = currentRoom->getConnectedRoom(whereToMove);
        return;
    }
    cout << "The is no room at the requested direction" << endl;
}

void Game::loadFromFile(string fileName)
{
    if (fileName.empty())
    {
        throw invalid_argument("Error : Invalid file name");
    }
    inputFile = ifstream(fileName);
    if (!inputFile)
    {
        throw runtime_error("Error : Couldn't open file");
    }
}

void Game::executeCommands()
{
    string line, arg;
    size_t posStart;
    size_t posEnd;

    while (getline(inputFile, line))
    {
        if (line.empty() || line.find("//") == 0)
            continue;

        stringstream streamString(line);
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
            throw invalid_argument("Error : Invalid input from file");
        }
    }
}

void Game::outputFinalState(std::string fileOutputName)
{
    
}

FightResult Game::fight(Monster &foulBeing)
{
    while (player->getCharacterHealth() > 0 && foulBeing.getMonsterHealth() > 0)
    {
        player->attack(foulBeing);
        if (foulBeing.getMonsterHealth() > 0)
        {
            foulBeing.attack(*player);
        }
        else
        {
            return VICTORY;
        }
    }
    return LOSE;
}

void Game::handleCreate(stringstream &ss)
{
    string arg2, arg3;
    ss >> arg2;
    ss >> arg3;
    if (arg2 == "Room")
    {
        dungeon.createRoom(arg3);
    }
    else if (arg2 == "Warrior")
    {
        Warrior PC(arg3);
        player = &PC;
    }
    else if (arg2 == "Thief")
    {
        Thief PC(arg3);
        player = &PC;
    }
    else if (arg2 == "Mage")
    {
        Mage PC(arg3);
        player = &PC;
    }
}

void Game::handleSet(stringstream &ss)
{
    string arg2, arg3;
    ss >> arg2;
    ss >> arg3;
    Room *tempStart = dungeon.findRoom(arg3);
    if (!tempStart)
    {
        throw std::invalid_argument("Error : start room was not found");
    }
    else
    {
        dungeon.setStartRoom(tempStart);
    }
}

void Game::handleConnect(stringstream &ss)
{
    string arg2, arg3, arg4;
    ss >> arg2;
    ss >> arg3;
    ss >> arg4;
    Directions direction = ALL_BLUE;
    if (arg4 == "North")
    {
        direction = NORTH;
    }
    else if (arg4 == "South")
    {
        direction = SOUTH;
    }
    else if (arg4 == "East")
    {
        direction = EAST;
    }
    else if (arg4 == "West")
    {
        direction = WEST;
    }
    if (direction == ALL_BLUE)
    {
        throw std::invalid_argument("Error : invalid direction");
    }
    else
    {
        dungeon.connectRoom(arg2, arg3, direction);
    }
}

void Game::handlePlace(stringstream &ss)
{
    string arg2;
    ss >> arg2;
    if (arg2 == "Monster")
    {
        handlePlaceMonster(ss);
    }
    else
    {
        handlePlaceItem(arg2, ss);
    }
}

void Game::handleEnter(stringstream &ss)
{
    string arg2, arg3;
    ss >> arg2;
    ss >> arg3;
    if (arg2 != "Dungeon")
    {
        throw invalid_argument("Error : Not a valid location to enter");
    }
    if (arg3 != player->getCharacterName())
    {
        throw invalid_argument("Error : This player does not exist");
    }
    currentRoom = dungeon.getStartRoom();
}

void Game::handleMove(stringstream &ss)
{
    string arg2, arg3;
    ss >> arg2;
    ss >> arg3;
    if (arg2 != player->getCharacterName())
    {
        throw invalid_argument("Error : Invalid player to move");
    }
    Directions whereToMove;
    if (arg3 == "North")
    {
        whereToMove = NORTH;
    }
    else if (arg3 == "South")
    {
        whereToMove = SOUTH;
    }
    else if (arg3 == "East")
    {
        whereToMove = EAST;
    }
    else if (arg3 == "West")
    {
        whereToMove = WEST;
    }
    else
    {
        throw invalid_argument("Error : Invalid direction");
    }
    if (currentRoom->getConnectedRoom(whereToMove))
    {
        currentRoom = currentRoom->getConnectedRoom(whereToMove);
    }
    else
    {
        throw invalid_argument("Error : No room connected in this direction");
    }
}

void Game::handleFight(stringstream &ss)
{
    string arg2, arg3;
    ss >> arg2;
    ss >> arg3;
    if (arg2 != player->getCharacterName())
    {
        throw invalid_argument("Error : Invalid player for the fight");
    }
    if (arg3 != (currentRoom->getMonster())->getMonsterName())
    {
        throw invalid_argument("Error : Invalid monster for the fight");
    }
    FightResult result = fight(*currentRoom->getMonster());
}

void Game::handlePickUp(stringstream &ss)
{
    string arg2, arg3;
    ss >> arg2;
    ss >> arg3;
    if (arg2 != player->getCharacterName())
    {
        throw invalid_argument("Error : Invalid player to pick up item");
    }
    if (arg3 == "Sword")
    {
        Item* itemToPickUp = currentRoom->findItem(SWORD);
        if (itemToPickUp)
        {
            player->pickUp(itemToPickUp);
        }
        else
        {
            throw invalid_argument("Error : No sword in the room");
        }
    }
    else if (arg3 == "Shield")
    {
        Item* itemToPickUp = currentRoom->findItem(SHIELD);
        if (itemToPickUp)
        {
            player->pickUp(itemToPickUp);
        }
        else
        {
            throw invalid_argument("Error : No shield in the room");
        }
    }
    else if (arg3 == "Dagger")
    {
        Item* itemToPickUp = currentRoom->findItem(DAGGER);
        if (itemToPickUp)
        {
            player->pickUp(itemToPickUp);
        }
        else
        {
            throw invalid_argument("Error : No dagger in the room");
        }
    }
    else if (arg3 == "Wand")
    {
        Item* itemToPickUp = currentRoom->findItem(WAND);
        if (itemToPickUp)
        {
            player->pickUp(itemToPickUp);
        }
        else
        {
            throw invalid_argument("Error : No wand in the room");
        }
    }
    else if (arg3 == "Health" || arg3 == "Strength" || arg3 == "Defense")
    {
        if (arg3 == "Health")
        {
            Item* itemToPickUp = currentRoom->findItem(POTION);
            if (!itemToPickUp)
            {
                throw invalid_argument("Error : No potion in the room");
            }
            else
            {
                Potion* temp = dynamic_cast <Potion*> (itemToPickUp);
                if (temp->getPotionType() != HEALTHP)
                {
                    throw invalid_argument("Error : No such potion in the room");
                }
                player->drinkPotion(itemToPickUp);
            }
        }
        else if (arg3 == "Strength")
        {
            Item* itemToPickUp = currentRoom->findItem(POTION);
            if (!itemToPickUp)
            {
                throw invalid_argument("Error : No potion in the room");
            }
            else
            {
                Potion* temp = dynamic_cast <Potion*> (itemToPickUp);
                if (temp->getPotionType() != STRENGTHP)
                {
                    throw invalid_argument("Error : No such potion in the room");
                }
                player->drinkPotion(itemToPickUp);
            }
        }
        else if (arg3 == "Defense")
        {
            Item* itemToPickUp = currentRoom->findItem(POTION);
            if (!itemToPickUp)
            {
                throw invalid_argument("Error : No potion in the room");
            }
            else
            {
                Potion* temp = dynamic_cast <Potion*> (itemToPickUp);
                if (temp->getPotionType() != DEFENSEP)
                {
                    throw invalid_argument("Error : No such potion in the room");
                }
                player->drinkPotion(itemToPickUp);
            }
        }
        else
        {
            throw invalid_argument("Error : Invalid potion type");
        }
    }
    else
    {
        throw invalid_argument("Error : Invalid item to pick up");
    }
}

void Game::handlePlaceMonster(stringstream &ss)
{
    string arg3, arg4;
    int arg5, arg6, arg7;
    ss >> arg3;
    ss >> arg4;
    ss >> arg5;
    ss >> arg6;
    ss >> arg7;
    Room *temp = dungeon.findRoom(arg4);
    if (!temp)
    {
        throw invalid_argument("Error : No room with the expected name");
    }

    if (arg5 < 0 || arg6 < 0 || arg7 < 0)
    {
        throw invalid_argument("Error : Invalid stats for monster");
    }
    Monster *monsterToAdd = new Monster(arg3, arg5, arg6, arg7);
    if (!monsterToAdd)
    {
        throw runtime_error("Error : No memory to create monster");
    }
    temp->placeMonster(monsterToAdd);
}

void Game::handlePlaceItem(string arg2, stringstream &ss)
{
    string arg3;
    int arg4, arg5, arg6;
    if (arg2 == "Sword")
    {
        ss >> arg3;
        ss >> arg4;
        ss >> arg5;
        ss >> arg6;
        Room *roomToPlace = dungeon.findRoom(arg3);
        if (!roomToPlace)
        {
            throw invalid_argument("Error : Invalid room to place in");
        }
        Sword *swordToAdd = new Sword(arg4, arg5, arg6);
        roomToPlace->placeItem(swordToAdd);
    }
    else if (arg2 == "Shield")
    {
        ss >> arg3;
        ss >> arg4;
        ss >> arg5;
        ss >> arg6;
        Room *roomToPlace = dungeon.findRoom(arg3);
        if (!roomToPlace)
        {
            throw invalid_argument("Error : Invalid room to place in");
        }
        Shield *shieldToAdd = new Shield(arg4, arg5, arg6);
        roomToPlace->placeItem(shieldToAdd);
    }
    else if (arg2 == "Dagger")
    {
        ss >> arg3;
        ss >> arg4;
        ss >> arg5;
        ss >> arg6;
        Room *roomToPlace = dungeon.findRoom(arg3);
        if (!roomToPlace)
        {
            throw invalid_argument("Error : Invalid room to place in");
        }
        Dagger *daggerToAdd = new Dagger(arg4, arg5, arg6);
        roomToPlace->placeItem(daggerToAdd);
    }
    else if (arg2 == "Wand")
    {
        ss >> arg3;
        ss >> arg4;
        ss >> arg5;
        ss >> arg6;
        Room *roomToPlace = dungeon.findRoom(arg3);
        if (!roomToPlace)
        {
            throw invalid_argument("Error : Invalid room to place in");
        }
        Wand *wandToAdd = new Wand(arg4, arg5, arg6);
        roomToPlace->placeItem(wandToAdd);
    }
    else if (arg2 == "Strength" || arg2 == "Health" || arg2 == "Defense")
    {
        string arg3, arg4;
        int arg5, arg6, arg7;
        ss >> arg3;
        ss >> arg4;
        ss >> arg5;
        ss >> arg6;
        ss >> arg7;
        Room *roomToPlace = dungeon.findRoom(arg4);
        if (!roomToPlace)
        {
            throw invalid_argument("Error : Invalid room to place in");
        }
        Potion *potionToAdd = new Potion(arg2, arg5, arg6, arg7);
        roomToPlace->placeItem(potionToAdd);
    }
    else
    {
        throw invalid_argument("Error : Trying to place an invalid argument");
    }
}
