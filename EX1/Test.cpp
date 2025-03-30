/*
Email: shanig7531@gmail.com
*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Graph.hpp"
#include "Algorithms.hpp"
#include "Queue.hpp"
#include "PriorityQueue.hpp"
#include "UnionFind.hpp"

// Tests for Graph Functions

TEST_CASE("Graph Functionality") {
    graph::Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 20);
    g.addEdge(3, 2, 15);

    CHECK(g.edgeCheck(0, 1) == true);
    CHECK(g.edgeCheck(1, 2) == true);
    CHECK(g.edgeCheck(0, 2) == false);

    g.removeEdge(0,1);
    CHECK(g.edgeCheck(0, 1) == false);

    CHECK(g.getVerticsCounter() == 5);

    CHECK(g.vertixCheck(1) == true);
    CHECK(g.vertixCheck(7) == false);


    // Checking the case for a directed graph
    graph::Graph tree(6);

    CHECK(tree.vertixCheck(5) == true);
    CHECK(tree.vertixCheck(10) == false);

    tree.addDirectedEdge(3,4,7);
    tree.addDirectedEdge(1,3,10);
    tree.addDirectedEdge(1,2,4);

    CHECK(tree.edgeCheck(3,4) == true);
    CHECK(tree.edgeCheck(1,3) == true);
    CHECK(tree.edgeCheck(2,4) == false);

    tree.removeEdge(3,4);
    CHECK(tree.edgeCheck(3,4) == false);


    // Checking the case for a graph without vertecies
    graph:: Graph g2(0);

    CHECK(g2.getVerticsCounter() == 0);

    g2.addEdge(3, 2, 15);
    CHECK(g2.edgeCheck(3,2) == false);

    // Checking the case for a graph without edges
    graph:: Graph g3(7);
    CHECK(g3.edgeCheck(3,2) == false);
    CHECK(g3.getVerticsCounter() == 7);

}

// Tests for Algorithms Functions
TEST_CASE("Algorithms funtionality"){

}

// Tests for Queue Functions
TEST_CASE("Queue funcionality"){
    Queue q(5);
    CHECK(q.isEmpty() == true);
    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(2);
    q.enqueue(8);
    CHECK(q.isFull() == true);
    CHECK(q.isEmpty() == false);

    CHECK(q.peek() == 3);

    CHECK(q.dequeue() == 3);
    CHECK(q.dequeue() == 5);
    CHECK(q.dequeue() == 10);
    CHECK(q.dequeue() == 2);
    CHECK(q.dequeue() == 8);

    CHECK(q.isEmpty() == true);

}


// Tests for PraiorityQueue Functions
TEST_CASE("PriorityQueue Functionality") {
    PriorityQueue pq(5);

    pq.enqueue(8, 2);
    pq.enqueue(0, 10);
    pq.enqueue(2, 4);
    pq.enqueue(10, 3);
    pq.enqueue(1, 5);
    CHECK(pq.isEmpty() == false);


    // Checking if the vertecies with the smallest "distances" will dequeue
    CHECK(pq.dequeue() == 8);
    CHECK(pq.dequeue() == 10);
    CHECK(pq.dequeue() == 2);

    CHECK(pq.peek() == 1);

    CHECK(pq.dequeue() == 1);
    CHECK(pq.dequeue() == 0);

    CHECK(pq.isEmpty() == true);

}


// Tests for UnionFind Functions
TEST_CASE("UnionFind Functionality") {
    UnionFind uf(5);
    
    CHECK(uf.find(0) == 0);
    CHECK(uf.find(1) == 1);
    
    uf.unionSets(0, 1);
    CHECK(uf.find(0) == uf.find(1));
}



