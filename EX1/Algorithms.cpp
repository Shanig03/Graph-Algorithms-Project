/*
Email: shanig7531@gmail.com
*/

#include "Algorithms.hpp"
#include "Queue.hpp"
#include "Graph.hpp"
#include "PriorityQueue.hpp"

const int INF = 1e9; // 1 billion, used to represent infinity

namespace graph {

    /*
    
    // Creating an undirected BFS tree
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
    */

    // Creating a directed BFS tree
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
                    bfsTree.addDirectedEdge(current, neighbor, weight);  // Use addDirectedEdge for directed tree
                    q.enqueue(neighbor);
                }
            }
        }
    
        delete[] visited;
        return bfsTree;
    }
    
    

    /*
    // Creating an undirected DFS tree
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
    */

    // Creating a directed DFS tree
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
                // Add the directed edge (parent to child) to the DFS tree
                dfsTree.addDirectedEdge(current, neighbor, weight);  // Use addDirectedEdge
                dfsVisit(graph, neighbor, visited, dfsTree);  // Recursively call DFS for the neighbor
            }
        }
    }
    
    /*
    // Creating an undirected SP tree 
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
    */

    // Creating a directed SP tree
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
    
        // Create a shortest path tree graph using addDirectedEdge for directed tree
        Graph shortestPathTree(V);
        for (int i = 0; i < V; i++) {
            if (parent[i] != -1) {
                shortestPathTree.addDirectedEdge(parent[i], i, dist[i] - dist[parent[i]]);
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
    


    /*


    Graph Algorithms::prim(Graph& g) {
        int numVertices = g.getVerticsCounter();  // Number of vertices in the graph
    
        // Create a priority queue to select the minimum weight edge
        PriorityQueue pq(numVertices);
    
        // Array to track the minimum weight of edges connecting vertices to the MST
        int* minEdge = new int[numVertices];
        // Array to track the parent vertex for each vertex in the MST
        int* parent = new int[numVertices];
        // Array to track whether a vertex is in the MST or not
        bool* inMST = new bool[numVertices];
        // Array to store the resulting MST (edges)
        Graph mst(numVertices);
    
        // Initialize all values to infinity and inMST to false
        for (int i = 0; i < numVertices; ++i) {
            minEdge[i] = INF;
            inMST[i] = false;
            parent[i] = -1;  // No parent initially
        }
    
        // Start from vertex 0
        int startVertex = 0;
        minEdge[startVertex] = 0;
        pq.enqueue(startVertex, 0);
    
        while (!pq.isEmpty()) {
            // Get the vertex with the minimum weight edge
            int u = pq.dequeue();
            inMST[u] = true;  // Include vertex u in MST
    
            // Traverse all neighbors of u
            for (int i = 0; i < g.getNeighborsCounter()[u]; ++i) {
                int v = g.getNeighborsList()[u][i].id;
                int weight = g.getNeighborsList()[u][i].weight;
    
                // If v is not in MST and the weight of edge (u, v) is smaller than the current minEdge[v]
                if (!inMST[v] && weight < minEdge[v]) {
                    minEdge[v] = weight;
                    parent[v] = u;  // Set u as the parent of v
                    pq.enqueue(v, minEdge[v]); // Add v to the priority queue
                }
            }
        }
    
        // Add edges to MST based on the parent array using addDirectedEdge
        for (int v = 1; v < numVertices; ++v) {
            int u = parent[v];
            if (u != -1) {
                // Add directed edge (u, v) with the weight of minEdge[v] to the MST
                mst.addDirectedEdge(u, v, minEdge[v]);
            }
        }
    
        // Clean up
        delete[] minEdge;
        delete[] inMST;
        delete[] parent;
    
        return mst;  // Return the MST
    }
    */

    Graph Algorithms::prim(Graph& g) {
        int numVertices = g.getVerticsCounter();  // Number of vertices in the graph
    
        // Create a priority queue to select the minimum weight edge
        PriorityQueue pq(numVertices);
    
        // Array to track the minimum weight of edges connecting vertices to the MST
        int* minEdge = new int[numVertices];
        // Array to track the parent vertex for each vertex in the MST
        int* parent = new int[numVertices];
        // Array to track whether a vertex is in the MST or not
        bool* inMST = new bool[numVertices];
        // Array to store the resulting MST (edges)
        Graph mst(numVertices);
    
        // Initialize all values to infinity and inMST to false
        for (int i = 0; i < numVertices; ++i) {
            minEdge[i] = INF;
            inMST[i] = false;
            parent[i] = -1;  // No parent initially
        }
    
        // Start from vertex 0
        int startVertex = 0;
        minEdge[startVertex] = 0;
        pq.enqueue(startVertex, 0);
    
        while (!pq.isEmpty()) {
            // Get the vertex with the minimum weight edge
            int u = pq.dequeue();
            inMST[u] = true;  // Include vertex u in MST
    
            // Traverse all neighbors of u
            for (int i = 0; i < g.getNeighborsCounter()[u]; ++i) {
                int v = g.getNeighborsList()[u][i].id;
                int weight = g.getNeighborsList()[u][i].weight;
    
                // If v is not in MST and the weight of edge (u, v) is smaller than the current minEdge[v]
                if (!inMST[v] && weight < minEdge[v]) {
                    minEdge[v] = weight;
                    parent[v] = u;  // Set u as the parent of v
                    pq.enqueue(v, minEdge[v]); // Add v to the priority queue
                }
            }
        }
    
        // Add edges to MST based on the parent array using addEdge for directed edges
        for (int v = 1; v < numVertices; ++v) {
            int u = parent[v];
            if (u != -1) {
                // Add directed edge (u, v) with the weight of minEdge[v] to the MST
                mst.addEdge(u, v, minEdge[v]);  // Add edge from u to v
            }
        }
    
        // Clean up
        delete[] minEdge;
        delete[] inMST;
        delete[] parent;
    
        return mst;  // Return the MST
    }
    

    
    



};