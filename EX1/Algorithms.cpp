/*
Email: shanig7531@gmail.com
*/

#include "Algorithms.hpp"
#include "Queue.hpp"
#include "Graph.hpp"
#include "PriorityQueue.hpp"

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


    Graph Algorithms::dijkstra(Graph& g, int src) {
        int V = g.getVerticsCounter();
        int* dist = new int[V];     // Distance array
        int* parent = new int[V];   // To store shortest path tree
        bool* visited = new bool[V]; // Visited array

        // Initialize distances to INF, visited to false, and parent to -1
        for (int i = 0; i < V; i++) {
            dist[i] = INF;
            visited[i] = false;
            parent[i] = -1;
        }
        dist[src] = 0; // Distance to source is 0

        PriorityQueue pq(V);
        pq.enqueue(src, 0); // Enqueue source vertex with distance 0

        while (!pq.isEmpty()) {
            int u = pq.dequeue(); // Get vertex with smallest distance
            visited[u] = true;

            neighborVertic* neighbors = g.getNeighborsList()[u];
            int neighborCount = g.getNeighborsCounter()[u];

            for (int i = 0; i < neighborCount; i++) {
                int v = neighbors[i].id;
                int weight = neighbors[i].weight;

                // Use the relax function to update the distance and parent
                relax(u, v, weight, dist, parent, pq);
            }
        }

        // Create a shortest path tree graph
        Graph shortestPathTree(V);
        for (int i = 0; i < V; i++) {
            if (parent[i] != -1) {
                shortestPathTree.addEdge(parent[i], i, dist[i] - dist[parent[i]]);
            }
        }

        // Clean up dynamically allocated memory
        delete[] dist;
        delete[] parent;
        delete[] visited;

        return shortestPathTree;  // Return the shortest path tree
    }

    
    
    // Function to relax an edge (u, v) with weight w
    void Algorithms::relax(int u, int v, int weight, int* dist, int* parent, PriorityQueue& pq) {
        // If the distance to v through u is shorter than the current distance
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            dist[v] = dist[u] + weight; // Update distance
            parent[v] = u; // Update parent
            pq.enqueue(v, dist[v]); // Enqueue v with updated distance
        }
    }



};