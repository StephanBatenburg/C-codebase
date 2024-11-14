#include "lists.hpp"

void lists::sl_list::push(void* data) {
    if (head == nullptr) {
        head = new Node;
        head->data = data;
        head->next = nullptr;
        listSize += 1;
        return;
    }

    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;

    listSize += 1;
}

void* lists::sl_list::pop() {
    if (head == nullptr) return nullptr;

    Node* newHead = head->next;
    void* toReturnData = head->data;
    delete head;
    head = newHead;
    listSize -= 1;

    return toReturnData;
}

void* lists::sl_list::getData(int index) {
    if (head == nullptr || index >= listSize) return nullptr;  

    Node* next = head;
    while (index > 0) {
        index -= 1;
        next = next->next;
    }

    return next->data;
}

int lists::sl_list::size() {
    return listSize;
}

bool lists::sl_list::isEmpty() {
    return head == nullptr;
}

int lists::sl_list::search(bool (*function)(void*, void*), void* toSearchData) {
    if (head == nullptr) return -1;

    Node* next = head;
    int counter = 0;
    while (next != nullptr) {
        if (function(next->data, toSearchData)) return counter;
        counter += 1;
        next = next->next;
    }

    return -1;
}

void lists::dl_list::insertAtHead(void* data) {
    if (head == nullptr) {
        head = new Node;
        head->data = data;
        head->next = nullptr;
        head->previous = nullptr;
        tail = head;
        listSize += 1;
        return;
    }

    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    newNode->previous = nullptr;
    head->previous = newNode;
    head = newNode;

    listSize += 1;
}

void lists::dl_list::insertAtTail(void* data) {
    if (head == nullptr) {
        insertAtHead(data);
        return;
    }

    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->previous = tail;
    tail->next = newNode;
    tail = newNode;

    listSize += 1;
}

void lists::dl_list::insertAtIndex(void* data, int index) {
    if (index < 0 || index > listSize) return;

    if (index == 0) {
        insertAtHead(data);
        return;
    } else if (index == listSize) {
        insertAtTail(data);
        return;
    }

    Node* next = head;
    while (index > 0) {
        next = next->next;
        index--;
    }

    Node* newNode = new Node;
    newNode->data = data;
    newNode->previous = next->previous;
    newNode->next = next;
    next->previous->next = newNode;
    next->previous = newNode;

    listSize += 1;
}

void* lists::dl_list::popHead() {
    if (head == nullptr) return nullptr;

    void* toReturnData = head->data;
    Node* newHead = head->next;

    if (newHead != nullptr) {
        newHead->previous = nullptr;
    } else {
        tail = nullptr;
    }

    delete head;
    head = newHead;
    listSize -= 1;

    return toReturnData;
}

void* lists::dl_list::popTail() {
    if (head == nullptr) return nullptr;

    void* toReturnData = tail->data;
    Node* newTail = tail->previous;

    if (newTail != nullptr) {
        newTail->next = nullptr;
    } else {
        head = nullptr;
    }

    delete tail;
    tail = newTail;
    listSize -= 1;

    return toReturnData;
}

void* lists::dl_list::popIndex(int index) {
    if (head == nullptr || index < 0 || index >= listSize) return nullptr;

    Node* targetNode;
    if (index <= listSize / 2) {
        targetNode = head;
        while (index > 0) {
            targetNode = targetNode->next;
            index--;
        }
    } else {
        targetNode = tail;
        while (index < listSize - 1) {
            targetNode = targetNode->previous;
            index++;
        }
    }

    void* toReturnData = targetNode->data;
    if (targetNode->previous != nullptr) targetNode->previous->next = targetNode->next;
    if (targetNode->next != nullptr) targetNode->next->previous = targetNode->previous;

    if (targetNode == head) head = targetNode->next;
    if (targetNode == tail) tail = targetNode->previous;

    delete targetNode;
    listSize -= 1;

    return toReturnData;
}

void* lists::dl_list::getData(int index) {
    if (head == nullptr || index >= listSize) return nullptr;

    Node* next = head;
    while (index > 0) {
        index -= 1;
        next = next->next;
    }

    return next->data;
}

int lists::dl_list::size() {
    return listSize;
}

bool lists::dl_list::isEmpty() {
    return head == nullptr;
}

int lists::dl_list::search(bool (*function)(void*, void*), void* toSearchData) {
    if (head == nullptr) return -1;

    Node* next = head;
    int counter = 0;
    while (next != nullptr) {
        if (function(next->data, toSearchData)) return counter;
        counter += 1;
        next = next->next;
    }

    return -1;
}