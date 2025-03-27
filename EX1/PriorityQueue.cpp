/*
Email: shanig7531@gmail.com
*/

#include "PriorityQueue.hpp"
#include <iostream>
#include <stdexcept>

PriorityQueue::PriorityQueue(int cap) {
    capacity = cap;
    size = 0;
    heap = new int[capacity];
    distances = new int[capacity];
}

PriorityQueue::~PriorityQueue() {
    delete[] heap;
    delete[] distances;
}

void PriorityQueue::heapifyUp(int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (distances[heap[parentIndex]] <= distances[heap[index]]) {
            break;
        }
        std::swap(heap[parentIndex], heap[index]);
        index = parentIndex;
    }
}

void PriorityQueue::heapifyDown(int index) {
    while (2 * index + 1 < size) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < size && distances[heap[leftChild]] < distances[heap[smallest]]) {
            smallest = leftChild;
        }
        if (rightChild < size && distances[heap[rightChild]] < distances[heap[smallest]]) {
            smallest = rightChild;
        }

        if (smallest != index) {
            std::swap(heap[smallest], heap[index]);
            index = smallest;
        } else {
            break;
        }
    }
}

void PriorityQueue::enqueue(int vertex, int dist) {
    if (size == capacity) {
        throw std::overflow_error("Priority Queue is full!");
    }
    heap[size] = vertex;
    distances[vertex] = dist;
    heapifyUp(size);
    size++;
}

int PriorityQueue::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Priority Queue is empty!");
    }
    int minVertex = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return minVertex;
}

bool PriorityQueue::isEmpty() {
    return size == 0;
}

void PriorityQueue::updateDistance(int vertex, int newDist) {
    for (int i = 0; i < size; i++) {
        if (heap[i] == vertex) {
            distances[vertex] = newDist;
            heapifyUp(i);
            break;
        }
    }
}

int PriorityQueue::peek() {
    if (isEmpty()) {
        throw std::underflow_error("Priority Queue is empty!");
    }
    return heap[0];
}

void PriorityQueue::display() {
    if (isEmpty()) {
        std::cout << "Priority Queue is empty!" << std::endl;
        return;
    }
    std::cout << "Priority Queue elements: ";
    for (int i = 0; i < size; i++) {
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
}
