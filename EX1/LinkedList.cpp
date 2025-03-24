/*
* Email: shanig7531@gmail.com
*/

#include "LinkedList.hpp"

LinkedList::LinkedList() : head(nullptr){}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::insert(int value) {
    Node* newNode = new Node(value);
    if(!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void LinkedList::print() const {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " -> "; 
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}







