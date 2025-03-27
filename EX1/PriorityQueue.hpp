/*
Email: shanig7531@gmail.com
*/

#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <stdexcept>
#include <iostream>

class PriorityQueue {
private:
    int* heap;         // Stores the vertex indices
    int* distances;    // Stores the corresponding distances of each vertex
    int capacity;
    int size;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    PriorityQueue(int cap);
    ~PriorityQueue();

    void enqueue(int vertex, int dist);
    int dequeue();
    bool isEmpty();
    void updateDistance(int vertex, int newDist);
    int peek();
    void display();
};

#endif // PRIORITYQUEUE_HPP
