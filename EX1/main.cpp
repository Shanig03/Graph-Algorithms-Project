/*
 Email: shanig7531@gmail.com
*/

#include <iostream>
#include "Graph.hpp"
#include "Queue.hpp"
#include "Algorithms.hpp"

int main() {
    /*
    graph::Graph g(5);   
    g.addEdge(0,3,2); 
    g.addEdge(1,4,1); 
    g.addEdge(4,2,3); 

    g.print_graph();

    g.removeEdge(1,4);

    std::cout << "After Deleting the edge (1,4): " << "\n" << std::endl;
    g.print_graph();

    Queue q(5);
    q.enqueue(0);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    q.display();

    q.dequeue();

    q.display();

    q.enqueue(10);

    q.display();

    std:: cout << q.peek() << std::endl;
    */

    graph::Graph g(5);   
    g.addEdge(0,3,2); 
    g.addEdge(1,4,1); 
    g.addEdge(4,2,3); 
    g.addEdge(0,1,3);
    g.addEdge(3,2,4);


    g.print_graph();

    graph::Graph tree = graph::Algorithms::BFS(g, 0);

    tree.print_graph();

    


    return 0;
}
