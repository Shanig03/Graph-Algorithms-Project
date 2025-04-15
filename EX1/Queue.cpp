/*
Email: shanig7531@gmail.com
*/

#include "Queue.hpp"
#include <iostream>

// Constructor: Initializes a queue with a given capacity
Queue::Queue(int vertics) {
    capacity = vertics;
    arr = new int[capacity];
    front = -1;
    end = -1;
    size = 0;  // Track the number of elements in the queue
}

// Destructor: Frees the dynamically allocated memory
Queue::~Queue() {
    delete[] arr;
}

// Checks if the queue is empty
bool Queue::isEmpty() {
    return size == 0;  // If size is 0, queue is empty
}


// Checks if the queue is full
bool Queue::isFull() {
    return size == capacity;  // If size is equal to capacity, queue is full
}

// Adds an element to the queue
void Queue::enqueue(int value) {
    if (isFull()) {
        std::cout << "Queue is full!" << std::endl;
        return;
    }
    if (front == -1) {  // If queue is empty
        front = 0;
    }
    end = (end + 1) % capacity;  // Circular increment
    arr[end] = value;
    size++;  // Increment the size
}


// Removes and returns the front element of the queue
int Queue::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue is empty!" << std::endl;
        return -1;  // Return -1 if the queue is empty
    }
    int dequeuedValue = arr[front];
    front = (front + 1) % capacity;  // Circular increment
    size--;  // Decrement the size
    if (size == 0) {  // Reset the pointers when the queue is empty
        front = -1;
        end = -1;
    }
    return dequeuedValue;
}


// Returns the front element without removing it
int Queue::peek() {
    if (isEmpty()) {
        std::cout << "Queue is empty!" << std::endl;
        return -1;
    }
    return arr[front];
}


// Displays the elements of the queue
void Queue::display() {
    if (isEmpty()) {
        std::cout << "Queue is empty!" << std::endl;
        return;
    }

    std::cout << "Queue elements: ";

    // Display elements in circular fashion
    for (int i = front; i != end; i = (i + 1) % capacity) {
        std::cout << arr[i] << " ";
    }
    std::cout << arr[end] << " ";  // Display the last element (at 'end')
    std::cout << std::endl;
}



