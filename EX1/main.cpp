/*
* Email: shanig7531@gmail.com
*/

#include <iostream>
#include "Graph.hpp"

int main() {
    graph::Graph g(5);   
    g.addEdge(0,3,2); 
    g.addEdge(1,4,1); 
    g.addEdge(4,2,3); 

    g.print_graph();

    g.removeEdge(1,4);

    std::cout << "After Deleting the edge (1,4): " << "\n" << std::endl;
    g.print_graph();

    return 0;
}
