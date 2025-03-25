/*
Email: shanig7531@gmail.com
*/

#include "PriorityQueue.hpp"
#include <iostream>
#include <stdexcept>

PriorityQueue::PriorityQueue(int capacity) {
    this->capacity = capacity;
    heap = new int[capacity];
    size = 0;
}

PriorityQueue::~PriorityQueue() {
    delete[] heap;  // Free the heap array
}

void PriorityQueue::enqueue(int value) {
    if (size == capacity) {
        std::cout << "Priority Queue is full!" << std::endl;
        return;  // Cannot insert more elements if the queue is full
    }

    // Insert the new value at the end of the heap
    heap[size] = value;
    size++;

    // Restore the heap property by "bubbling up" the element
    heapifyUp(size - 1);
}

int PriorityQueue::dequeue() {
    if (isEmpty()) {
        std::cout << "Priority Queue is empty!" << std::endl;
        return -1;  // Return -1 to indicate empty queue
    }

    // The root of the heap is the min element
    int minElement = heap[0];

    // Move the last element to the root
    heap[0] = heap[size - 1];
    size--;  // Decrease the size

    // Restore the heap property by "bubbling down" the root element
    heapifyDown(0);

    return minElement;
}

int PriorityQueue::peek() {
    if (isEmpty()) {
        std::cout << "Priority Queue is empty!" << std::endl;
        return -1;  // Return -1 to indicate empty queue
    }

    return heap[0];  // The root is the minimum element
}

bool PriorityQueue::isEmpty() {
    return size == 0;  // The queue is empty if size is 0
}

void PriorityQueue::display() {
    if (isEmpty()) {
        std::cout << "Priority Queue is empty!" << std::endl;
        return;
    }

    std::cout << "Priority Queue elements: ";
    for (int i = 0; i < size; ++i) {
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
}

void PriorityQueue::heapifyUp(int index) {
    // Bubble up the element at index 'index' to restore heap property
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[parentIndex] <= heap[index]) {
            break;  // If the parent is smaller or equal, the heap property is satisfied
        }

        // Swap the current node with its parent
        std::swap(heap[parentIndex], heap[index]);
        index = parentIndex;  // Move up to the parent's index
    }
}

void PriorityQueue::heapifyDown(int index) {
    // Bubble down the element at index 'index' to restore heap property
    while (2 * index + 1 < size) {  // If the left child exists
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        // Check if the left child is smaller than the current element
        if (leftChild < size && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }

        // Check if the right child is smaller than the current element
        if (rightChild < size && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }

        // If the smallest element is not the current one, swap and continue
        if (smallest != index) {
            std::swap(heap[smallest], heap[index]);
            index = smallest;  // Move down to the smallest child's index
        } else {
            break;  // The heap property is satisfied
        }
    }
}
