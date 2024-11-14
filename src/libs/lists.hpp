#pragma once

namespace lists {
    class sl_list{
        private:

        typedef struct Node{
            void* data;
            Node* next;
        }Node;

        int listSize = 0;
        Node* head = nullptr;

        public:
        
        void push(void* data);
        //should free(delete) the data yourself you get from pop()
        void* pop();
        void* getData(int index);
        int size();
        bool isEmpty();
        int search(bool (*function)(void*, void*), void* toSearchData);
    };

    class dl_list{
        private:

        typedef struct Node{
            void* data;
            Node* next;
            Node* previous;
        }Node;

        int listSize = 0;
        Node* head = nullptr;
        Node* tail = nullptr;

        public:

        void insertAtHead(void* data);
        void insertAtTail(void* data);
        //Indexes start at 0. if index > listsize it will put data at the tail.
        void insertAtIndex(void* data, int index);

        void* popHead();
        void* popTail();
        void* popIndex(int index);
        void* getData(int index);

        int size();
        bool isEmpty();
        int search(bool (*function)(void*, void*), void* toSearchData);
    };
}