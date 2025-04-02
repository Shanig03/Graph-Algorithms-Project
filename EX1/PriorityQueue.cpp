/*
Email: shanig7531@gmail.com
*/

#include "PriorityQueue.hpp"
#include <iostream>
#include <stdexcept>

// Constractor for PriorityQueue class - initializes an empty priority queue with a given capacity
PriorityQueue::PriorityQueue(int cap) {
    capacity = cap;
    size = 0;
    heap = new int[capacity]; // Stores vertex IDs
    distances = new int[capacity]; // Stores distances corresponding to heap positions
}

// Distractor for PriorityQueue class
PriorityQueue::~PriorityQueue() {
    delete[] heap;
    delete[] distances;
}

// Restores heap property by moving an element up
void PriorityQueue::heapifyUp(int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (distances[index] >= distances[parentIndex]) {
            break;
        }
        std::swap(heap[parentIndex], heap[index]);
        std::swap(distances[parentIndex], distances[index]);
        index = parentIndex;
    }
}

// Restores heap property by moving an element down
void PriorityQueue::heapifyDown(int index) {
    while (2 * index + 1 < size) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < size && distances[leftChild] < distances[smallest]) {
            smallest = leftChild;
        }
        if (rightChild < size && distances[rightChild] < distances[smallest]) {
            smallest = rightChild;
        }

        if (smallest != index) {
            std::swap(heap[smallest], heap[index]);
            std::swap(distances[smallest], distances[index]);
            index = smallest;
        } else {
            break;
        }
    }
}

// Inserts a new vertex with its distance into the priority queue
void PriorityQueue::enqueue(int vertex, int dist) {
    if (size == capacity) {
        throw std::overflow_error("Priority Queue is full!");
    }
    heap[size] = vertex;
    distances[size] = dist;
    heapifyUp(size);
    size++;
}

// Removes and returns the vertex with the smallest distance
int PriorityQueue::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Priority Queue is empty!");
    }
    int minVertex = heap[0];
    heap[0] = heap[size - 1];
    distances[0] = distances[size - 1];
    size--;
    heapifyDown(0);
    return minVertex;
}

// Checks if the priority queue is empty
bool PriorityQueue::isEmpty() {
    return size == 0;
}


// Updates the distance of a given vertex in the priority queue
void PriorityQueue::updateDistance(int vertex, int newDist) {
    for (int i = 0; i < size; i++) {
        if (heap[i] == vertex) {
            int oldDist = distances[i];
            distances[i] = newDist;
            if (newDist < oldDist) {
                heapifyUp(i);
            } else {
                heapifyDown(i);
            }
            break;
        }
    }
}

// Returns the vertex with the smallest distance without removing it
int PriorityQueue::peek() {
    if (isEmpty()) {
        throw std::underflow_error("Priority Queue is empty!");
    }
    return heap[0];
}


// Displays the current elements in the priority queue
void PriorityQueue::display() {
    if (isEmpty()) {
        std::cout << "Priority Queue is empty!" << std::endl;
        return;
    }
    std::cout << "Priority Queue elements: ";
    for (int i = 0; i < size; i++) {
        std::cout << heap[i] << "(" << distances[i] << ") ";
    }
    std::cout << std::endl;
}

