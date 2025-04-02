/*
Email: shanig7531@gmail.com
*/

#include <iostream>
#include "Graph.hpp"
#include "Queue.hpp"
#include "Algorithms.hpp"
#include "PriorityQueue.hpp"

int main() {

    graph::Graph graphWithNoVertecies(0);
    std::cout << "Graph with 0 vertecies was created" << std::endl;
    graphWithNoVertecies.print_graph();
    std::cout << "Graph with 0 vertecies was printed" << std::endl;

    
    try
    {
        graph::Graph graphWithNegativeVertecies(-10);   
        std::cout << "Graph with -10 vertecies was created" << std::endl;
        graphWithNegativeVertecies.print_graph();
        std::cout << "Graph with -10 vertecies was printed" << std::endl;
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    // Demonstraiting the usage of the Graph and Algorithms classes

    graph::Graph g(6);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 4, 2);
    g.addEdge(4, 5, 6);


    // Printing the original graph
    std::cout << "\nOriginal Graph:" << std::endl;
    g.print_graph();


    // Printing the output graph of the BFS algorithm
    graph::Graph bfsTree = graph::Algorithms::BFS(g,0);
    std::cout << "\n BFS (from vertic 0) : \n";
    bfsTree.print_graph();

    // Printing the output graph of the DFS algorithm
    graph::Graph dfsTree = graph::Algorithms::DFS(g, 0);
    std::cout << "\n DFS (from vertic 0) : \n";
    dfsTree.print_graph();


    // Printing the output graph of the Dijkstra algorithm
    graph::Graph dijkstraTree = graph::Algorithms::dijkstra(g, 0);
    std::cout << "\n Dijkstra (from vertic 0) : \n";
    dijkstraTree.print_graph();

    // Printing the output graph of the Prim algorithm
    graph::Graph primTree = graph::Algorithms::prim(g);
    std::cout << "\n Prim : \n";
    primTree.print_graph();

    // Printing the output graph of the Kruskal algorithm
    graph::Graph kruskalTree = graph::Algorithms::kruskal(g);
    std::cout << "\n Kruskal : \n";
    kruskalTree.print_graph();


    return 0;
   
}
