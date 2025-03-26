/*
Email: shanig7531@gmail.com
*/

#include <iostream>
#include "Graph.hpp"
#include "Queue.hpp"
#include "Algorithms.hpp"
#include "PriorityQueue.hpp"

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




    
    //graph::Graph tree = graph::Algorithms::BFS(g, 0);


    graph::Graph tree = graph::Algorithms::DFS(g, 4);

    tree.print_graph();


     // Create a PriorityQueue with capacity of 10 elements
    PriorityQueue pq(10);

    // Test enqueueing elements
    std::cout << "Enqueueing elements 5, 3, 8, 1, 6:" << std::endl;
    pq.enqueue(5);
    pq.enqueue(3);
    pq.enqueue(8);
    pq.enqueue(1);
    pq.enqueue(6);
    pq.display();  // Should display the priority queue after enqueueing

    // Test peeking (should return the smallest element, which is 1)
    std::cout << "Peek: " << pq.peek() << std::endl;

    // Test dequeueing (should return and remove the smallest element, which is 1)
    std::cout << "Dequeue: " << pq.dequeue() << std::endl;
    pq.display();  // Display the priority queue after dequeueing

    // Test dequeueing again (should return and remove the next smallest element, which is 3)
    std::cout << "Dequeue: " << pq.dequeue() << std::endl;
    pq.display();  // Display the priority queue after dequeueing

    // Test enqueueing again to check dynamic behavior
    std::cout << "Enqueueing elements 2, 4, 7:" << std::endl;
    pq.enqueue(2);
    pq.enqueue(4);
    pq.enqueue(7);
    pq.display();  // Display the priority queue after enqueueing

    // Test dequeueing until the queue is empty
    std::cout << "Dequeue: " << pq.dequeue() << std::endl;
    std::cout << "Dequeue: " << pq.dequeue() << std::endl;
    std::cout << "Dequeue: " << pq.dequeue() << std::endl;
    std::cout << "Dequeue: " << pq.dequeue() << std::endl;
    pq.display();  // Should show empty queue
    */


    graph::Graph g(5);   
    g.addEdge(0,3,2); 
    g.addEdge(1,4,1); 
    g.addEdge(4,2,3); 
    g.addEdge(0,1,3);
    g.addEdge(3,2,4);
    g.addEdge(0,1,5);
    g.addEdge(4,3,1);


    g.print_graph();


    graph::Graph gr = graph::Algorithms::dijkstra(g, 4);

    gr.print_graph();
    
    


    return 0;
}
