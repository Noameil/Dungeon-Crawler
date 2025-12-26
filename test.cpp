// #include <iostream>
// #include <string>
// #include "List.hpp"

// // A simple class to test with pointers/objects
// struct TestItem
// {
//     std::string name;
//     bool operator==(const TestItem &other) const { return name == other.name; }
// };

// // Overload << for printList() to work with TestItem*
// std::ostream &operator<<(std::ostream &os, const TestItem &obj)
// {
//     return os << obj.name;
// }

// int main()
// {
//     // We use int* to match your printList implementation: std::cout << *curr->data
//     List<int *> list;

//     std::cout << "--- Test 1: Empty List State ---" << std::endl;
//     std::cout << "Is Empty: " << (list.isEmpty() ? "Yes" : "No") << std::endl;
//     std::cout << "Size: " << list.size() << std::endl;

//     std::cout << "\n--- Test 2: Single Element Operations ---" << std::endl;
//     int val1 = 10;
//     list.insertStart(&val1);
//     std::cout << "Size after 1 insert: " << list.size() << std::endl;
//     list.remove(&val1);
//     std::cout << "Size after removing only element: " << list.size() << std::endl;
//     // Note: Watch out if your remove logic sets head/tail to nullptr or back to a dummy node!

//     std::cout << "\n--- Test 3: Head and Tail Specific Deletion ---" << std::endl;
//     int a = 1, b = 2, c = 3;
//     list.insertEnd(&a);
//     list.insertEnd(&b);
//     list.insertEnd(&c);

//     std::cout << "List before removing head (1): " << std::endl;
//     list.printList();

//     list.remove(&a); // Removing Head
//     std::cout << "List after removing head: " << std::endl;
//     list.printList();

//     list.remove(&c); // Removing Tail
//     std::cout << "List after removing tail (3): " << std::endl;
//     list.printList();

//     std::cout << "\n--- Test 4: Insert After Tail ---" << std::endl;
//     int d = 4;
//     list.insertAfterNode(&b, &d); // 'b' is the only node left, so it is the tail
//     std::cout << "List after inserting 4 after tail 2: " << std::endl;
//     list.printList();

//     std::cout << "\n--- Test 5: Removing non-existent data ---" << std::endl;
//     int fake = 99;
//     try
//     {
//         list.remove(&fake);
//         std::cout << "Handled non-existent remove successfully." << std::endl;
//     }
//     catch (...)
//     {
//         std::cout << "CRASH: Removing non-existent item failed!" << std::endl;
//     }

//     // std::cout << "\n--- Test 6: Mass insertions/deletions for Valgrind ---" << std::endl;
//     // for (int i = 0; i < 100; ++i)
//     // {
//     //     int *n = new int(i);
//     //     list.insertStart(n);
//     // }
//     // for (int i = 0; i < count; i++)
//     // {
//     //     /* code */
//     // }

//     // // This will test if your destructor actually clears all 100+ nodes.

//     std::cout << "\nTests Complete. Run with Valgrind to check for leaks!" << std::endl;

//     return 0;
// }