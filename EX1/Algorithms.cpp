/*
Email: shanig7531@gmail.com
*/

#include "Algorithms.hpp"
#include "Queue.hpp"
#include "Graph.hpp"

namespace graph {

    Graph Algorithms::BFS(Graph& graph, int startVertex) {
        int numVertices = graph.getVerticsCounter();
        Graph bfsTree(numVertices);  
        bool* visited = new bool[numVertices]();  // Initialize all to false
        Queue q(numVertices);
    
        int* neighborsCounter = graph.getNeighborsCounter();
        neighborVertic** neighborsList = graph.getNeighborsList();
    
        visited[startVertex] = true;
        q.enqueue(startVertex);
    
        while (!q.isEmpty()) {
            int current = q.dequeue();
    
            for (int i = 0; i < neighborsCounter[current]; ++i) {
                int neighbor = neighborsList[current][i].id;
                int weight = neighborsList[current][i].weight;
    
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    bfsTree.addEdge(current, neighbor, weight);  // Add one direction
                    q.enqueue(neighbor);
                }
            }
        }
    
        delete[] visited;
        return bfsTree;
    }
    


    Graph Algorithms::DFS(Graph& graph, int startVertex) {
        int numVertices = graph.getVerticsCounter();
        Graph dfsTree(numVertices);  // The tree graph to return
        bool* visited = new bool[numVertices]();  // Initialize all to false
        
        // Call the recursive DFS helper function
        dfsVisit(graph, startVertex, visited, dfsTree);
        
        delete[] visited;
        return dfsTree;
    }

    // Recursive helper function for DFS
    void Algorithms::dfsVisit(Graph& graph, int current, bool* visited, Graph& dfsTree) {
        visited[current] = true;  // Mark the current vertex as visited
        
        // Traverse the adjacency list of the current vertex
        int* neighborsCounter = graph.getNeighborsCounter();
        neighborVertic** neighborsList = graph.getNeighborsList();
        
        for (int i = 0; i < neighborsCounter[current]; ++i) {
            int neighbor = neighborsList[current][i].id;
            int weight = neighborsList[current][i].weight;
            
            if (!visited[neighbor]) {
                // Add the edge to the DFS tree and recurse on the neighbor
                dfsTree.addEdge(current, neighbor, weight);
                dfsVisit(graph, neighbor, visited, dfsTree);  // Recursively call DFS for the neighbor
            }
        }
    }



};