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
    string line;
    size_t posStart;
    size_t posEnd;

    while (getline(inputFile, line))
    {
        if (line.empty() || line.find("//") == 0)
            continue;

        stringstream streamString(line);
        string arg;
        streamString >> arg;
        if (arg == "" || arg == " ")
            continue;
        if (arg == "Create")
        {
            try
            {
                handleCreate(streamString);
            }
            catch (const std::exception &e)
            {
                e.what();
            }
        }
        else if (arg == "Set")
        {
            try
            {
                handleSet(streamString);
            }
            catch (exception &e)
            {
                e.what();
            }
        }
        else if (arg == "Connect")
        {
            try
            {
                handleConnect(streamString);
            }
            catch (const std::exception &e)
            {
                e.what();
            }
        }
        else if (arg == "Place")
        {
            try
            {
                handlePlace(streamString);
            }
            catch (const std::exception &e)
            {
                e.what();
            }
        }
        else if (arg == "Enter")
        {
            try
            {
                handleEnter(streamString);
            }
            catch (const std::exception &e)
            {
                e.what();
            }
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
            try
            {
                handlePickUp(streamString);
            }
            catch (exception &e)
            {
                cout << e.what() << endl;
                continue;
            }
        }
        else
        {
            throw invalid_argument("Error : Invalid input from file");
        }
        streamString.str("");
        streamString.clear();
    }
}

void Game::outputFinalState(std::string fileOutputName)
{
    ofstream outputFile(fileOutputName);
    if (!outputFile.is_open())
    {
        throw runtime_error("Error : Couldn't output to the file");
    }
    List<Character *>::Node *temp = players.head;
    while (temp)
    {
        int health = temp->data->getCharacterHealth();
        Item *item1 = temp->data->getFirstItem();
        Item *item2 = temp->data->getSecondItem();
        outputFile << temp->data->getCharacterName() << " final stats: Health " << temp->data->getCharacterHealth() << " Strength: " << temp->data->getCharacterStrength() << " Defense: " << temp->data->getCharacterDefense() << endl;
        if (item1 && item2)
        {
            outputFile << item1->getName() << ": " << item1->getItemHealthBonus() << "/" << item1->getItemStrengthBonus() << "/" << item1->getItemDefenseBonus() << endl;
            outputFile << item2->getName() << ": " << item2->getItemHealthBonus() << "/" << item2->getItemStrengthBonus() << "/" << item2->getItemDefenseBonus() << endl;
        }
        else if (item1)
        {
            outputFile << item1->getName() << ": " << item1->getItemHealthBonus() << "/" << item1->getItemStrengthBonus() << "/" << item1->getItemDefenseBonus() << endl;
        }
        else if (item2)
        {
            outputFile << item2->getName() << ": " << item2->getItemHealthBonus() << "/" << item2->getItemStrengthBonus() << "/" << item2->getItemDefenseBonus() << endl;
        }
        else
        {
            outputFile << temp->data->getCharacterName() << " had no items (and still won eze gever nishba)!" << endl;
        }
        temp = temp->next;
    }
}

FightResult Game::fight(Character *player, Monster *foulBeing)
{
    while (player->getCharacterHealth() > 0 && foulBeing->getMonsterHealth() > 0)
    {
        player->attack(*foulBeing);
        if (foulBeing->getMonsterHealth() > 0)
        {
            foulBeing->attack(*player);
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
        Warrior *PC = new Warrior(arg3);
        players.insertEnd(PC);
    }
    else if (arg2 == "Thief")
    {
        Thief *PC = new Thief(arg3);
        players.insertEnd(PC);
    }
    else if (arg2 == "Mage")
    {
        Mage *PC = new Mage(arg3);
        players.insertEnd(PC);
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
        std::cout << "Error : Start room could not be found" << std::endl;
        return;
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
        std::cout << "Error : Invalid direction" << std::endl;
        return;
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
    Character *player = findPlayer(arg3);
    if (!player)
    {
        cout << "Error : No existing player to enter the dungeon" << endl;
        return;
    }

    currentRoom = dungeon.getStartRoom();
}

void Game::handleMove(stringstream &ss)
{
    string arg2, arg3;
    ss >> arg2;
    ss >> arg3;
    Character *player = findPlayer(arg2);
    if (!player)
    {
        cout << "Error : No existing player to move" << endl;
        return;
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
        throw invalid_argument("Error : Invalid direction from handleMove");
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
    Character *fightingPlayer = findPlayer(arg2);
    Monster *fightingMonster = currentRoom->findMonster(arg3);
    if (fightingPlayer && fightingMonster)
    {
        FightResult result = fight(fightingPlayer, fightingMonster);
    }
}

void Game::handlePickUp(stringstream &ss)
{
    string arg2, arg3;
    ss >> arg2;
    ss >> arg3;
    Character *player = findPlayer(arg2);
    if (!player)
    {
        cout << "Error : Invalid player to pick up item" << endl;
        return;
    }
    if (arg3 == "Sword")
    {
        Item *itemToPickUp = currentRoom->findItem(SWORD);
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
        Item *itemToPickUp = currentRoom->findItem(SHIELD);
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
        Item *itemToPickUp = currentRoom->findItem(DAGGER);
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
        Item *itemToPickUp = currentRoom->findItem(WAND);
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
            Item *itemToPickUp = currentRoom->findItem(POTION);
            if (!itemToPickUp)
            {
                throw invalid_argument("Error : No potion in the room");
            }
            else
            {
                Potion *temp = dynamic_cast<Potion *>(itemToPickUp);
                if (temp->getPotionType() != HEALTHP)
                {
                    throw invalid_argument("Error : No such potion in the room");
                }
                player->drinkPotion(itemToPickUp);
            }
        }
        else if (arg3 == "Strength")
        {
            Item *itemToPickUp = currentRoom->findItem(POTION);
            if (!itemToPickUp)
            {
                throw invalid_argument("Error : No potion in the room");
            }
            else
            {
                Potion *temp = dynamic_cast<Potion *>(itemToPickUp);
                if (temp->getPotionType() != STRENGTHP)
                {
                    throw invalid_argument("Error : No such potion in the room");
                }
                player->drinkPotion(itemToPickUp);
            }
        }
        else if (arg3 == "Defense")
        {
            Item *itemToPickUp = currentRoom->findItem(POTION);
            if (!itemToPickUp)
            {
                throw invalid_argument("Error : No potion in the room");
            }
            else
            {
                Potion *temp = dynamic_cast<Potion *>(itemToPickUp);
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
        cout << "Error : No such room was found" << endl;
        return;
    }

    if (arg5 < 0 || arg6 < 0 || arg7 < 0)
    {
        cout << "Error : Invalid stats for monster" << endl;
        return;
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
            cout << "Error : No such room was found" << endl;
            return;
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
            cout << "Error : No such room was found" << endl;
            return;
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
            cout << "Error : No such room was found" << endl;
            return;
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
            cout << "Error : No such room was found" << endl;
            return;
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
            cout << "Error : No such room was found" << endl;
            return;
        }
        Potion *potionToAdd = new Potion(arg2, arg5, arg6, arg7);
        roomToPlace->placeItem(potionToAdd);
    }
    else
    {
        cout << "Error : Trying to place an invalid item" << endl;
    }
}

Character *Game::findPlayer(std::string name)
{
    List<Character *>::Node *temp = players.head;
    while (temp)
    {
        if (temp->data->getCharacterName() == name)
        {
            return temp->data;
        }
        temp = temp->next;
    }
    cout << "Error : Player not found" << endl;
    return nullptr;
}
