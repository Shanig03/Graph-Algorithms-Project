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

    // Checking thr case for a graph eith negative number of vertecies
    CHECK_THROWS_AS(graph:: Graph g2(-2), std::invalid_argument);



}

// Tests for Algorithms Functions
TEST_CASE("Algorithms funtionality"){

    graph::Graph gr(6);
    gr.addEdge(0, 1, 4);
    gr.addEdge(0, 2, 3);
    gr.addEdge(1, 2, 1);
    gr.addEdge(1, 3, 2);
    gr.addEdge(2, 3, 4);
    gr.addEdge(3, 4, 2);
    gr.addEdge(4, 5, 6);

    graph::Graph bfsTree = graph::Algorithms::BFS(gr, 0);

    CHECK(bfsTree.edgeCheck(0,1) == true);
    CHECK(bfsTree.edgeCheck(0,2) == true);
    CHECK(bfsTree.edgeCheck(1,3) == true);
    CHECK(bfsTree.edgeCheck(3,4) == true);
    CHECK(bfsTree.edgeCheck(4,5) == true);

    CHECK(bfsTree.edgeCheck(5,0) == false);
    CHECK(bfsTree.edgeCheck(2,1) == false);
    CHECK(bfsTree.edgeCheck(3,2) == false);
    CHECK(bfsTree.edgeCheck(2,4) == false);
    CHECK(bfsTree.edgeCheck(5,2) == false);


    graph::Graph dfsTree = graph::Algorithms::DFS(gr, 0);

    CHECK(dfsTree.edgeCheck(0,1) == true);
    CHECK(dfsTree.edgeCheck(1,2) == true);
    CHECK(dfsTree.edgeCheck(2,3) == true);
    CHECK(dfsTree.edgeCheck(3,4) == true);
    CHECK(dfsTree.edgeCheck(4,5) == true);

    CHECK(dfsTree.edgeCheck(5,0) == false);
    CHECK(dfsTree.edgeCheck(2,1) == false);
    CHECK(dfsTree.edgeCheck(3,2) == false);
    CHECK(dfsTree.edgeCheck(2,4) == false);
    CHECK(dfsTree.edgeCheck(5,2) == false);


    graph::Graph dijTree = graph::Algorithms::dijkstra(gr, 0);

    CHECK(dijTree.edgeCheck(0,1) == true);
    CHECK(dijTree.edgeCheck(0,2) == true);
    CHECK(dijTree.edgeCheck(1,3) == true);
    CHECK(dijTree.edgeCheck(3,4) == true);
    CHECK(dijTree.edgeCheck(4,5) == true);

    CHECK(dijTree.edgeCheck(1,0) == false);
    CHECK(dijTree.edgeCheck(2,0) == false);
    CHECK(dijTree.edgeCheck(3,1) == false);
    CHECK(dijTree.edgeCheck(4,3) == false);
    CHECK(dijTree.edgeCheck(5,4) == false);

    
    graph::Graph primGraph = graph::Algorithms::prim(gr);

    CHECK(primGraph.edgeCheck(0,2) == true);
    CHECK(primGraph.edgeCheck(2,1) == true);
    CHECK(primGraph.edgeCheck(1,3) == true);
    CHECK(primGraph.edgeCheck(3,4) == true);
    CHECK(primGraph.edgeCheck(4,5) == true);

    CHECK(primGraph.edgeCheck(1,0) == false);
    CHECK(primGraph.edgeCheck(2,3) == false);


    graph::Graph kruskalGraph = graph::Algorithms::kruskal(gr);
    CHECK(primGraph.edgeCheck(0,2) == true);
    CHECK(primGraph.edgeCheck(2,1) == true);
    CHECK(primGraph.edgeCheck(1,3) == true);
    CHECK(primGraph.edgeCheck(3,4) == true);
    CHECK(primGraph.edgeCheck(4,5) == true);

    CHECK(primGraph.edgeCheck(1,0) == false);
    CHECK(primGraph.edgeCheck(2,3) == false);




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
    CHECK(uf.find(2) == 2);
    CHECK(uf.find(3) == 3);
    CHECK(uf.find(4) == 4);


    uf.unionSets(0, 1);
    CHECK(uf.find(0) == uf.find(1));

    uf.unionSets(2,3);
    CHECK(uf.find(2) == uf.find(3));

    uf.unionSets(2,4);
    CHECK(uf.find(2) == uf.find(4));
    CHECK(uf.find(3) == uf.find(4));

    uf.unionSets(2,0);
    CHECK(uf.find(2) == uf.find(0));
    CHECK(uf.find(3) == uf.find(1));

}



