#include <iostream>
#include <cassert>
#include "libs/lists.hpp"

#define NDEBUG

using namespace lists;

bool intSearch(void* data, void* toSearchData) {
    return *(int*)data == *(int*)toSearchData;
}

const char* boolToString(bool b){
    return b ? "True" : "False";
}

int main() {
    // Test sl_list (singly linked list)
    std::cout << "Testing sl_list..." << std::endl;
    sl_list singleList;

    // Push some elements to sl_list
    int a = 5, b = 10, c = 15;
    singleList.push(&a);
    singleList.push(&b);
    singleList.push(&c);

    // Check list size
    assert(singleList.size() == 3);
    std::cout << "sl_list size after pushes: " << singleList.size() << std::endl;

    // Check the top element (should be 'c' = 15)
    int* popped = (int*)singleList.pop();
    assert(*popped == 15);
    std::cout << "Popped from sl_list: " << *popped << std::endl;

    // Check list size after pop
    assert(singleList.size() == 2);
    std::cout << "sl_list size after pop: " << singleList.size() << std::endl;

    // Test getData method (index 0 should return 'b' = 10)
    int* data = (int*)singleList.getData(0);
    assert(*data == 10);
    std::cout << "sl_list getData(0): " << *data << std::endl;

    // Test searching an element
    int searchData = 10;
    int index = singleList.search(intSearch, &searchData);
    assert(index == 0);  // 'b' = 10 should be at index 0
    std::cout << "Found 10 at index " << index << " in sl_list." << std::endl;

    // Test if list is empty
    assert(!singleList.isEmpty());
    std::cout << "sl_list is empty: " << boolToString(singleList.isEmpty()) << std::endl;

    // Pop all elements to empty the list
    singleList.pop();
    singleList.pop();
    assert(singleList.isEmpty());
    std::cout << "sl_list is empty after popping all elements: " << boolToString(singleList.isEmpty()) << std::endl;

    // Test dl_list (doubly linked list)
    std::cout << "\nTesting dl_list..." << std::endl;
    dl_list doubleList;

    // Insert elements at head and tail
    doubleList.insertAtHead(&a); // a = 5
    doubleList.insertAtTail(&b); // b = 10
    doubleList.insertAtHead(&c); // c = 15

    // Check list size
    assert(doubleList.size() == 3);
    std::cout << "dl_list size after inserts: " << doubleList.size() << std::endl;

    // Pop elements from head and tail
    int* poppedHead = (int*)doubleList.popHead();
    assert(*poppedHead == 15);
    std::cout << "Popped from head of dl_list: " << *poppedHead << std::endl;

    int* poppedTail = (int*)doubleList.popTail();
    assert(*poppedTail == 10);
    std::cout << "Popped from tail of dl_list: " << *poppedTail << std::endl;

    // Check list size after pops
    assert(doubleList.size() == 1);
    std::cout << "dl_list size after pops: " << doubleList.size() << std::endl;

    // Test getData method (index 0 should return 'a' = 5)
    data = (int*)doubleList.getData(0);
    assert(*data == 5);
    std::cout << "dl_list getData(0): " << *data << std::endl;

    // Test inserting at index
    int d = 20;
    doubleList.insertAtIndex(&d, 0); // Should insert 20 at index 0
    data = (int*)doubleList.getData(0);
    assert(*data == 20);
    std::cout << "Inserted 20 at index 0 in dl_list. getData(0): " << *data << std::endl;

    // Test searching an element
    searchData = 20;
    index = doubleList.search(intSearch, &searchData);
    assert(index == 0);  // 20 should be at index 0
    std::cout << "Found 20 at index " << index << " in dl_list." << std::endl;

    // Test if list is empty
    assert(!doubleList.isEmpty());
    std::cout << "dl_list is empty: " << boolToString(doubleList.isEmpty()) << std::endl;

    //checks if list size is indeed two
    assert(doubleList.size() == 2);
    std::cout << "list size: " << doubleList.size() << std::endl;

    std::cout << "popping last two items" << std::endl;
    // Pop the last element to empty the list
    doubleList.popTail();

    std::cout << "popping last item" << std::endl;
    doubleList.popTail();
    std::cout << "popped last items" << std::endl;
    assert(doubleList.isEmpty());
    std::cout << "dl_list is empty after popping all elements: " << boolToString(doubleList.isEmpty()) << std::endl;

    std::cout << "\n All singly linked + doubly linked list tests passed!" << std::endl;
    return 0;

    std::system("pause");
}
