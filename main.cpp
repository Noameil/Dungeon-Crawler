// Noam Eilat : 322713025
// Amit Lachmann : 207448267

#include <iostream>
#include "List.hpp"
#include "Item.hpp"

int main()
{

    Game game;
    game.loadFromFile("input.txt");

    // Run game logic based on loaded commands
    game.executeCommands();

    game.outputFinalState("output.txt");

    // List<int *> list;
    // int x = 1;
    // int y = 2;
    // int z = 3;
    // int k = 4;
    // // std::cout << list.isEmpty() << std::endl;
    // list.insertEnd(&x);
    // list.insertEnd(&y);
    // // list.insertAfterNode(&x, &z);
    // // list.insertStart(&k);
    // // std::cout << list.isEmpty() << std::endl;
    // // std::cout << list.size() << std::endl;
    // list.printList();
    // list.remove(&x);
    // list.printList();

    return 0;
}