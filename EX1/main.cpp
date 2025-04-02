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

    
    try {
        graph::Graph graphWithNegativeVertecies(-10);   
        std::cout << "Graph with -10 vertecies was created" << std::endl;
        graphWithNegativeVertecies.print_graph();
    }
    catch(const std::invalid_argument& e){
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
    std::cout << "\n BFS (from vertic 0): \n";
    bfsTree.print_graph();

    // Printing the output graph of the DFS algorithm
    graph::Graph dfsTree = graph::Algorithms::DFS(g, 0);
    std::cout << "\n DFS (from vertic 0): \n";
    dfsTree.print_graph();


    // Printing the output graph of the Dijkstra algorithm
    graph::Graph dijkstraTree = graph::Algorithms::dijkstra(g, 0);
    std::cout << "\n Dijkstra (from vertic 0): \n";
    dijkstraTree.print_graph();

    // Printing the output graph of the Prim algorithm
    graph::Graph primTree = graph::Algorithms::prim(g);
    std::cout << "\n Prim: \n";
    primTree.print_graph();

    // Printing the output graph of the Kruskal algorithm
    graph::Graph kruskalTree = graph::Algorithms::kruskal(g);
    std::cout << "\n Kruskal: \n";
    kruskalTree.print_graph();


    // Graph with negative weights
    graph::Graph gr(8);
    gr.addEdge(0, 1, -4);
    gr.addEdge(0, 2, 3);
    gr.addEdge(1, 2, -1);
    gr.addEdge(1, 3, 2);
    gr.addEdge(2, 3, -4);
    gr.addEdge(3, 4, 2);
    gr.addEdge(4, 5, -6);
    gr.addEdge(6, 5, -2);
    gr.addEdge(7, 5, 7);


    // Printing the original graph
    std::cout << "\nOriginal Graph with negative weights:" << std::endl;
    gr.print_graph();

    // Should print "Dijkstra algorithem can't use negative weights" 
    std::cout << "\n Dijkstra (with negative weights): \n";
    graph::Graph dijTree = graph::Algorithms::dijkstra(gr, 3);
    dijTree.print_graph();
    
    // Printing the output graph of the BFS algorithm
    graph::Graph bfsTree2 = graph::Algorithms::BFS(gr,3);
    std::cout << "\n BFS (from vertic 3): \n";
    bfsTree2.print_graph();

    // Printing the output graph of the DFS algorithm
    graph::Graph dfsTree2 = graph::Algorithms::DFS(gr, 3);
    std::cout << "\n DFS (from vertic 3): \n";
    dfsTree2.print_graph();    

    // Printing the output graph of the Prim algorithm
    graph::Graph primTree2 = graph::Algorithms::prim(gr);
    std::cout << "\n Prim: \n";
    primTree2.print_graph();

    // Printing the output graph of the Kruskal algorithm
    graph::Graph kruskalTree2 = graph::Algorithms::kruskal(gr);
    std::cout << "\n Kruskal: \n";
    kruskalTree2.print_graph();


    return 0;
   
}
