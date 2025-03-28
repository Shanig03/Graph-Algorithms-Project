#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Graph.hpp"
#include "Algorithms.hpp"
#include "Queue.hpp"
#include "PriorityQueue.hpp"
#include "UnionFind.hpp"

TEST_CASE("Graph Basic Functionality") {
    graph::Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 20);
    
    CHECK(g.edgeCheck(0, 1) == true);
    CHECK(g.edgeCheck(1, 2) == true);
    CHECK(g.edgeCheck(0, 2) == false);
}

TEST_CASE("UnionFind Functionality") {
    UnionFind uf(5);
    
    CHECK(uf.find(0) == 0);
    CHECK(uf.find(1) == 1);
    
    uf.unionSets(0, 1);
    CHECK(uf.find(0) == uf.find(1));
}

TEST_CASE("PriorityQueue Functionality") {
    PriorityQueue pq(5);
    pq.enqueue(0, 10);
    pq.enqueue(1, 5);
    CHECK(pq.dequeue() == 1);
    CHECK(pq.dequeue() == 0);
}

