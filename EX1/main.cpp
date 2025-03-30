/*
Email: shanig7531@gmail.com
*/

#include <iostream>
#include "Graph.hpp"
#include "Queue.hpp"
#include "Algorithms.hpp"
#include "PriorityQueue.hpp"

int main() {

    graph::Graph g(6);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 4, 2);
    g.addEdge(4, 5, 6);


    std::cout << "Original Graph:" << std::endl;
    g.print_graph();

    std::cout << "\n BFS (from vertic 0) : \n";
    graph::Graph bfsTree = graph::Algorithms::BFS(g, 0);
    bfsTree.print_graph();

    std::cout << "\n DFS (from vertic 0) : \n";
    graph::Graph dfsTree = graph::Algorithms::DFS(g, 0);
    dfsTree.print_graph();

    std::cout << "\n Dijkstra (from vertic 0) : \n";
    graph::Graph dijkstraTree = graph::Algorithms::dijkstra(g, 0);
    dijkstraTree.print_graph();

    std::cout << "\n Prim : \n";
    graph::Graph primTree = graph::Algorithms::prim(g);
    primTree.print_graph();

    std::cout << "\n Kruskal : \n";
    graph::Graph kruskalTree = graph::Algorithms::kruskal(g);
    kruskalTree.print_graph();


    return 0;
   
}
