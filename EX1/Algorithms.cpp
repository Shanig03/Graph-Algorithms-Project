/*
Email: shanig7531@gmail.com
*/

#include "Algorithms.hpp"
#include "Queue.hpp"
#include "Graph.hpp"
#include "PriorityQueue.hpp"
#include <limits>

const int INF = 1e9;

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


    Graph Algorithms::dijkstra(Graph g, int src) {
        int V = g.getVerticsCounter();
        int* dist = new int[V];  // Distance array
        bool* visited = new bool[V];  // Visited array
    
        // Initialize distances to INF and visited to false
        for (int i = 0; i < V; i++) {
            dist[i] = INF;
            visited[i] = false;
        }
        dist[src] = 0;  // Distance to source is 0
    
        PriorityQueue pq(V);
        pq.enqueue(src);
    
        while (!pq.isEmpty()) {
            int u = pq.dequeue();  // Get the vertex with the smallest distance
            visited[u] = true;
    
            // Process all neighbors
            neighborVertic* neighbors = g.getNeighborsList()[u];
            int neighborCount = g.getNeighborsCounter()[u];
    
            for (int i = 0; i < neighborCount; i++) {
                int v = neighbors[i].id;
                int weight = neighbors[i].weight;
    
                if (!visited[v] && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.enqueue(v);
                }
            }
        }
    
        // Print shortest distances
        std::cout << "Vertex   Distance from Source " << src << std::endl;
        for (int i = 0; i < V; i++) {
            std::cout << i << "\t" << (dist[i] == INF ? -1 : dist[i]) << std::endl;
        }
    
        // Clean up dynamically allocated memory
        delete[] dist;
        delete[] visited;
    
        return g;  // Returning Graph (you may modify based on your needs)
    }



};