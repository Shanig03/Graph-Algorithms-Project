#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>

class LinkedList {
    private:
    struct Node{
        int id;
        int weight;
        Node* next;
    };
    Node* head;

    public:
    LinkedList();

    ~LinkedList();

    void insert(int value);

    void remove(int value);
    
    void print() const;
};



#endif