/*
Email: shanig7531@gmail.com
*/

#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <stdexcept>
#include <iostream>

class PriorityQueue {
private:
    int* heap; // Stores the vertex indices
    int* distances; // Stores the corresponding distances of each vertex
    int capacity;
    int size;

    void heapifyUp(int index); // Restores the heap property by moving an element up
    void heapifyDown(int index); // Restores the heap property by moving an element down

public:
    PriorityQueue(int cap); // Constructor: Initializes a priority queue with a given capacity

    ~PriorityQueue(); // Destructor: Frees dynamically allocated memory

    void enqueue(int vertex, int dist); // Inserts a vertex with a given distance into the priority queue
    
    int dequeue(); // Removes and returns the vertex with the smallest distance
    
    bool isEmpty(); // Checks if the priority queue is empty
    
    void updateDistance(int vertex, int newDist); // Updates the distance of a given vertex in the priority queue
    
    int peek(); // Returns the vertex with the smallest distance without removing it
    
    void display(); // Displays the contents of the priority queue
};

#endif 
