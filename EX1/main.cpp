/*
Email: shanig7531@gmail.com
*/

#include <iostream>
#include "Graph.hpp"
#include "Queue.hpp"
#include "Algorithms.hpp"
#include "PriorityQueue.hpp"


// Function to run all the algorithms for a graph
void runAlgorithms(graph::Graph& g, const std::string& graphName, int src = 0) {
    std::cout << "\n~~~ " << graphName << " ~~~\n";
    std::cout << " The original Graph: " << std::endl;
    g.print_graph();

    // Printing the output graph of the BFS algorithm
    std::cout << "\n BFS - from vertex " << src << ":\n";
    graph:: Graph bfsTree = graph::Algorithms::BFS(g, src);
    bfsTree.print_graph();

    // Printing the output graph of the DFS algorithm, might be a forest
    std::cout << "\n DFS - from vertex " << src << ": \n";
    graph::Graph dfsTree = graph::Algorithms::DFS(g, src);
    dfsTree.print_graph();

    // Printing the output graph of the Dijkstra algorithm (shortests paths tree)
    std::cout << "\n Dijkstra - from vertex " << src << ": \n";
    graph::Graph dijkstraTree = graph::Algorithms::dijkstra(g, src);
    dijkstraTree.print_graph();

    // Printing the output graph of the Prim algorithm (minimum spanning tree)
    std::cout << "\n Prim: \n";
    graph::Graph primTree = graph::Algorithms::prim(g);
    primTree.print_graph();

    // Printing the output graph of the Kruskal algorithm (minimum spanning tree)
    std::cout << "\n Kruskal: \n";
    graph::Graph kruskalTree = graph::Algorithms::kruskal(g);
    kruskalTree.print_graph();

    std::cout << "=====================" << std::endl;
}



int main() {

    // Example for graph with 0 vertecis
    graph::Graph graphWithNoVertecies(0);
    std::cout << "Graph with 0 vertecies was created" << std::endl;
    graphWithNoVertecies.print_graph();
    std::cout << "Graph with 0 vertecies was printed" << std::endl;


    // Example for trying to initiate a graph with a negative number of vertecis
    try {
        graph::Graph graphWithNegativeVertecies(-10);   
    }
    catch(const std::invalid_argument& e){
        std::cerr << e.what() << '\n';
    }


    
    // Demonstraiting the usage of Graph and Algorithms classes

    // Regular graph
    graph::Graph regularGraph(6);
    regularGraph.addEdge(0, 1, 4);
    regularGraph.addEdge(0, 2, 3);
    regularGraph.addEdge(1, 2, 1);
    regularGraph.addEdge(1, 3, 2);
    regularGraph.addEdge(2, 3, 4);
    regularGraph.addEdge(3, 4, 2);
    regularGraph.addEdge(4, 5, 6);

    runAlgorithms(regularGraph,"Regular Graph", 0);

    graph::Graph cycleGraph(5);
    cycleGraph.addEdge(0, 1, 3);
    cycleGraph.addEdge(1, 2, 7);
    cycleGraph.addEdge(2, 3, 6);
    cycleGraph.addEdge(3, 4, 5);
    cycleGraph.addEdge(4, 1, 4);

    runAlgorithms(cycleGraph, "Cyclic Graph", 0);


    // Graph with negative weights
    graph::Graph negativeGraph(8);
    negativeGraph.addEdge(0, 1, -4);
    negativeGraph.addEdge(0, 2, 3);
    negativeGraph.addEdge(1, 2, -1);
    negativeGraph.addEdge(1, 3, 2);
    negativeGraph.addEdge(2, 3, -4);
    negativeGraph.addEdge(3, 4, 2);
    negativeGraph.addEdge(4, 5, -6);
    negativeGraph.addEdge(6, 5, -2);
    negativeGraph.addEdge(7, 5, 7);

    runAlgorithms(negativeGraph,"Graph with negative weights", 3);


    // Graph with 2 connectivity components
    graph::Graph unconnectedGraph(7);
   
    unconnectedGraph.addEdge(0, 1, 4);
    unconnectedGraph.addEdge(0, 3, 3);
    unconnectedGraph.addEdge(1, 2, 5);
    unconnectedGraph.addEdge(2, 4, 5);
    unconnectedGraph.addEdge(5, 6, 8);
    

    runAlgorithms(unconnectedGraph,"Unconnected Graph", 0);
    

    return 0;
   
}


