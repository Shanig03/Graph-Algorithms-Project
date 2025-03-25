

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
    
        




};