/*
Email: shanig7531@gmail.com
*/

#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

class PriorityQueue {
private:
    int* heap;       // Array to store the heap elements
    int capacity;    // Capacity of the heap (max number of elements)
    int size;        // Current number of elements in the heap

    // Helper functions to maintain heap property
    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    // Constructor and Destructor
    PriorityQueue(int capacity);
    ~PriorityQueue();

    // Basic operations
    void enqueue(int value);  // Add element
    int dequeue(); // Remove and return the min element
    int peek(); // Return the min element without removing it
    bool isEmpty(); // Check if the queue is empty
    void display(); // Display the elements in the priority queue
};

#endif
