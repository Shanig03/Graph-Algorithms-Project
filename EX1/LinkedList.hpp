/*
* Email: shanig7531@gmail.com
*/

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>

struct Node{
    int id;
    int weight;
    Node* next;
};

class LinkedList {
    private:
    
    Node* head;

    public:
    LinkedList();

    ~LinkedList();

    void insert(int value);

    void remove(int value);
    
    void print() const;
};



#endif