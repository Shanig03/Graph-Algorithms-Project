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

    SUBCASE("Regular graph"){
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
    }

    SUBCASE("Directed graph"){
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
    }

    SUBCASE("Graph without vertecies"){
        // Checking the case for a graph without vertecies
        graph:: Graph g2(0);

        CHECK(g2.getVerticsCounter() == 0);

        g2.addEdge(3, 2, 15);
        CHECK(g2.edgeCheck(3,2) == false);
    }

    
    SUBCASE("Graph without edges"){
        // Checking the case for a graph without edges
        graph:: Graph g3(7);
        CHECK(g3.edgeCheck(3,2) == false);
        CHECK(g3.getVerticsCounter() == 7);
    }

    SUBCASE("Graph with negative number of vertecies"){
        // Checking the case for a graph with negative number of vertecies
        CHECK_THROWS_AS(graph:: Graph g2(-2), std::invalid_argument);
    }
    
}

// Tests for BFS algorithm
TEST_CASE("BFS funtionality"){

    graph::Graph gr(6);
    gr.addEdge(0, 1, 4);
    gr.addEdge(0, 2, 3);
    gr.addEdge(1, 2, 1);
    gr.addEdge(1, 3, 2);
    gr.addEdge(2, 3, 4);
    gr.addEdge(3, 4, 2);
    gr.addEdge(4, 5, 6);
    
    CHECK(gr.getVerticsCounter() == 6);

    graph::Graph bfsTree = graph::Algorithms::BFS(gr, 0);

    // Checking if all the tree edge is in the bfsTree
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

    // Checking if the number of vertecis is the same after the algorithm
    CHECK(bfsTree.getVerticsCounter() == 6);

    // Starting the BFS from a non valid vertex
    graph::Graph bfsTree2 = graph::Algorithms::DFS(gr, -1);
    // Returns an empty graph
    CHECK(bfsTree2.getVerticsCounter() == 0);
}


// Tests for DFS algorithm
TEST_CASE("DFS funtionality"){

    SUBCASE("DFS on regular graph"){
        graph::Graph gr(6);
        gr.addEdge(0, 1, 4);
        gr.addEdge(0, 2, 3);
        gr.addEdge(1, 2, 1);
        gr.addEdge(1, 3, 2);
        gr.addEdge(2, 3, 4);
        gr.addEdge(3, 4, 2);
        gr.addEdge(4, 5, 6);

        graph::Graph dfsTree = graph::Algorithms::DFS(gr, 0);

        // Checking if all the tree edge is in the dfsTree
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

        // Checking if the number of vertecis is the same after the algorithm
        CHECK(dfsTree.getVerticsCounter() == 6);

        graph::Graph dfsTree2 = graph::Algorithms::DFS(gr, -1);

        CHECK(dfsTree2.getVerticsCounter() == 0);
    }
    
    SUBCASE("Unconnected graph"){
        // Checking for an unconnected graph
        graph::Graph gr2(7);
    
        gr2.addEdge(0, 1, 4);
        gr2.addEdge(0, 3, 3);
        gr2.addEdge(1, 2, 5);
        gr2.addEdge(2, 4, 5);
        gr2.addEdge(5, 6, 8);

        graph::Graph dfsForest = graph::Algorithms::DFS(gr2, 0);

        // Checking if all the tree edge is in the dfsForest
        CHECK(dfsForest.edgeCheck(0,1) == true);
        CHECK(dfsForest.edgeCheck(1,2) == true);
        CHECK(dfsForest.edgeCheck(2,4) == true);
        CHECK(dfsForest.edgeCheck(0,3) == true);
        CHECK(dfsForest.edgeCheck(5,6) == true);

        CHECK(dfsForest.edgeCheck(3,5) == false);
        CHECK(dfsForest.edgeCheck(2,1) == false);
        CHECK(dfsForest.edgeCheck(3,0) == false);
        CHECK(dfsForest.edgeCheck(5,2) == false);
    }
    

}

// Tests for Dijkstra algorithm
TEST_CASE("Dijkstra funtionality"){

    SUBCASE("Regular graph"){
        graph::Graph gr(6);
        gr.addEdge(0, 1, 4);
        gr.addEdge(0, 2, 3);
        gr.addEdge(1, 2, 1);
        gr.addEdge(1, 3, 2);
        gr.addEdge(2, 3, 4);
        gr.addEdge(3, 4, 2);
        gr.addEdge(4, 5, 6);

        graph::Graph dijTree = graph::Algorithms::dijkstra(gr, 0);

        // Checking if all the tree edge is in the dijTree
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

        // Checking if the number of vertecis is the same after the algorithm
        CHECK(dijTree.getVerticsCounter() == 6);
    }

    SUBCASE("Graph with negative weights"){

        // Graph with negative weights
        graph::Graph negativeGraph(5);
        negativeGraph.addEdge(0, 1, -4);
        negativeGraph.addEdge(0, 2, 3);
        negativeGraph.addEdge(0, 3, 4);
        negativeGraph.addEdge(1, 4, -7);

        graph::Graph dijTree2 = graph::Algorithms::dijkstra(negativeGraph, 0);

        // Checking if the number of the vertecis in the returned graph is 0 for a graph with negative weights
        CHECK(dijTree2.getVerticsCounter() == 0);
    }


    SUBCASE("Unconnected graph"){
        // Graph with 2 connectivity components
        graph::Graph gr2(7);
    
        gr2.addEdge(0, 1, 4);
        gr2.addEdge(0, 3, 3);
        gr2.addEdge(1, 2, 5);
        gr2.addEdge(2, 4, 5);
        gr2.addEdge(5, 6, 8);

        graph::Graph dijTree3 = graph::Algorithms::dijkstra(gr2, 0);

        CHECK(dijTree3.edgeCheck(0,1) == true);
        CHECK(dijTree3.edgeCheck(0,3) == true);
        CHECK(dijTree3.edgeCheck(1,2) == true);
        CHECK(dijTree3.edgeCheck(2,4) == true);

        CHECK(dijTree3.edgeCheck(2,0) == false);
        CHECK(dijTree3.edgeCheck(3,5) == false);
        CHECK(dijTree3.edgeCheck(4,3) == false);
        CHECK(dijTree3.edgeCheck(5,6) == false);
    }


}

// Tests for Prim algorithm
TEST_CASE("Prim funtionality"){

    graph::Graph gr(6);
    gr.addEdge(0, 1, 4);
    gr.addEdge(0, 2, 3);
    gr.addEdge(1, 2, 1);
    gr.addEdge(1, 3, 2);
    gr.addEdge(2, 3, 4);
    gr.addEdge(3, 4, 2);
    gr.addEdge(4, 5, 6);

    graph::Graph primGraph = graph::Algorithms::prim(gr);

    // Checking if all the tree edge is in the primGraph
    CHECK(primGraph.edgeCheck(0,2) == true);
    CHECK(primGraph.edgeCheck(2,1) == true);
    CHECK(primGraph.edgeCheck(1,3) == true);
    CHECK(primGraph.edgeCheck(3,4) == true);
    CHECK(primGraph.edgeCheck(4,5) == true);

    CHECK(primGraph.edgeCheck(1,0) == false);
    CHECK(primGraph.edgeCheck(2,3) == false);

    // Checking if the number of vertecis is the same after the algorithm
    CHECK(primGraph.getVerticsCounter() == 6);

    // For a MST the number of edges should be |E|-1
    CHECK(primGraph.getNumOfEdges() == 5);
}

// Tests for Kruskal algorithm
TEST_CASE("Kruskal funtionality"){

    graph::Graph gr(6);
    gr.addEdge(0, 1, 4);
    gr.addEdge(0, 2, 3);
    gr.addEdge(1, 2, 1);
    gr.addEdge(1, 3, 2);
    gr.addEdge(2, 3, 4);
    gr.addEdge(3, 4, 2);
    gr.addEdge(4, 5, 6);


    graph::Graph kruskalGraph = graph::Algorithms::kruskal(gr);

    // Checking if all the tree edge is in the kruskalGraph
    CHECK(kruskalGraph.edgeCheck(0,2) == true);
    CHECK(kruskalGraph.edgeCheck(2,1) == true);
    CHECK(kruskalGraph.edgeCheck(1,3) == true);
    CHECK(kruskalGraph.edgeCheck(3,4) == true);
    CHECK(kruskalGraph.edgeCheck(4,5) == true);

    CHECK(kruskalGraph.edgeCheck(1,0) == false);
    CHECK(kruskalGraph.edgeCheck(2,3) == false);

    // Checking if the number of vertecis is the same after the algorithm
    CHECK(kruskalGraph.getVerticsCounter() == 6);

    // For a MST the number of edges should be |E|-1
    CHECK(kruskalGraph.getNumOfEdges() == 5);

    SUBCASE("Test for the selection sort"){

        // Creating an array of edges
        Edge* testEdges = new Edge[5];

        testEdges[0].dest = 0;
        testEdges[0].src = 1;
        testEdges[0].weight = 5;

        testEdges[1].dest = 1;
        testEdges[1].src = 2;
        testEdges[1].weight = 3;

        testEdges[2].dest = 2;
        testEdges[2].src = 3;
        testEdges[2].weight = 10;

        testEdges[3].dest = 3;
        testEdges[3].src = 4;
        testEdges[3].weight = 1;

        testEdges[4].dest = 4;
        testEdges[4].src = 0;
        testEdges[4].weight = 8;

        // Sorting them by weight
        graph::Algorithms::sortEdges(testEdges,5);

        // Checking that the testEdges array is sorted by weight
        CHECK(testEdges[0].src == 4);
        CHECK(testEdges[0].dest == 3);

        CHECK(testEdges[1].src == 2);
        CHECK(testEdges[1].dest == 1);

        CHECK(testEdges[2].src == 1);
        CHECK(testEdges[2].dest == 0);

        CHECK(testEdges[3].src == 0);
        CHECK(testEdges[3].dest == 4);

        CHECK(testEdges[4].src == 3);
        CHECK(testEdges[4].dest == 2);

        // Cleaning the allocated memory
        delete[] testEdges;
    }
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



