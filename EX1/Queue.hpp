/*
Email: shanig7531@gmail.com
*/

#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue {
private:
    int* arr;
    int front, end, capacity, size;  

public:
    // Constructor to initialize the queue
    Queue(int size);

    // Destructor to free memory
    ~Queue();

    // Check if the queue is empty
    bool isEmpty();

    // Check if the queue is full
    bool isFull();

    // Enqueue: Add an element to the queue
    void enqueue(int value);

    // Dequeue: Remove an element from the queue
    int dequeue();

    // Peek: Get the front element of the queue
    int peek();

    // Display the queue
    void display();
};

#endif
