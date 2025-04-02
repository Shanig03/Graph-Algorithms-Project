/*
Email: shanig7531@gmail.com
*/

#include "Algorithms.hpp"
#include "Queue.hpp"
#include "Graph.hpp"
#include "PriorityQueue.hpp"
#include "UnionFind.hpp"

const int INF = 1e9; // 1 billion, used to represent infinity

namespace graph {


    // Implementation of BFS algorithm, returns a directed BFS tree
    Graph Algorithms::BFS(Graph& graph, int startVertex) {
        // Check whether the starting vertex is valid
        if (startVertex < 0){
            std::cout << "Starting vertex is not valid" << std::endl;
            Graph g(0);
            return g;
        }

        // Creating the lists needed for the algorithm and the tree for the algorithm output
        int numVertices = graph.getVerticsCounter();
        Graph bfsTree(numVertices);  
        bool* visited = new bool[numVertices]();  // Initialize all to false
        Queue q(numVertices);
    
        int* neighborsCounter = graph.getNeighborsCounter();
        neighborVertic** neighborsList = graph.getNeighborsList();
    
        // Starting from the startVertex fro the given input
        visited[startVertex] = true;
        q.enqueue(startVertex);
    
        // Looping until the queue is empty, meaning the loop went over all the vertecies
        while (!q.isEmpty()) {
            int current = q.dequeue(); // Taking the first vertex from the queue
    
            // Looping over all of the current vertex neighbors
            for (int i = 0; i < neighborsCounter[current]; ++i) {
                int neighbor = neighborsList[current][i].id;
                int weight = neighborsList[current][i].weight;
    
                // Checking if the vertex were not visited yet
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    // Adding the edge between the current vertex to his neighbor
                    bfsTree.addDirectedEdge(current, neighbor, weight);  
                    q.enqueue(neighbor); // Adding the vertex to the queue
                }
            }
        }

        // Deleting the allocated memory
        delete[] visited;
        return bfsTree;
    }
    

    // Implementation of DFS algorithm, returns a directed DFS tree
    Graph Algorithms::DFS(Graph& graph, int startVertex) {
        // Check whether the starting vertex is valid
        if (startVertex < 0){
            std::cout << "Starting vertex is not valid" << std::endl;
            Graph g(0);
            return g;
        }

        // Creating the lists needed for the algorithm and the tree for the algorithm output
        int numVertices = graph.getVerticsCounter();
        Graph dfsTree(numVertices);  // The tree graph to return
        bool* visited = new bool[numVertices]();  // Initialize all to false
        
        // Call the recursive DFS helper function
        dfsVisit(graph, startVertex, visited, dfsTree);
        
        // Deleting the allocated memory
        delete[] visited;
        return dfsTree;
    }

    
    // Recursive helper function for DFS algorithm
    void Algorithms::dfsVisit(Graph& graph, int current, bool* visited, Graph& dfsTree) {
        visited[current] = true;  // Mark the current vertex as visited
        
        // Taking the adjacency list of the current vertex
        int* neighborsCounter = graph.getNeighborsCounter();
        neighborVertic** neighborsList = graph.getNeighborsList();
        
        // Looping over all of the current vertex neighbors
        for (int i = 0; i < neighborsCounter[current]; ++i) {
            int neighbor = neighborsList[current][i].id;
            int weight = neighborsList[current][i].weight;
            
            // Checking if the vertex were not visited yet
            if (!visited[neighbor]) {
                // Add the directed edge (parent to child) to the DFS tree
                dfsTree.addDirectedEdge(current, neighbor, weight);
                dfsVisit(graph, neighbor, visited, dfsTree);  // Recursively call DFS for the neighbor
            }
        }
    }

    // Implementation of dijkstra algorithm, returns a directed shortest pathes tree
    Graph Algorithms::dijkstra(Graph& g, int src) {
        // Check whether the src is valid for dijkstra - not negative
        if (src < 0){
            std::cout << "Starting vertex is not valid" << std::endl;
            Graph g(0);
            return g;
        }

        // Creating the lists needed for the algorithm
        int V = g.getVerticsCounter();
        int* dist = new int[V]; // Distance array
        int* parent = new int[V];
        bool* visited = new bool[V]; // Visited array
    
        // Initialize distances to INF, visited to false, and parent to -1
        for (int i = 0; i < V; i++) {
            dist[i] = INF;
            visited[i] = false;
            parent[i] = -1;
        }

        dist[src] = 0; // Distance to source is 0
    
        // Initializing a PriorityQueue
        PriorityQueue pq(V);
        pq.enqueue(src, 0); // Enqueue src vertex with distance 0
    
        while (!pq.isEmpty()) {
            int u = pq.dequeue(); // Get vertex with smallest distance
            visited[u] = true;
    
            neighborVertic* neighbors = g.getNeighborsList()[u];
            int neighborCount = g.getNeighborsCounter()[u];
    
            for (int i = 0; i < neighborCount; i++) {
                int v = neighbors[i].id;
                int weight = neighbors[i].weight;

                // Checking if the weight is negative, if it does- deleting al the allocated memeory and returning an empty graph
                if (weight < 0) {
                    std::cout << "Dijkstra algorithem can't use negative weights" << std::endl;
                    graph::Graph graph1(0);
                    delete[] dist;
                    delete[] parent;
                    delete[] visited;
                    return graph1;
                }
    
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
    
        return shortestPathTree;
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
    

    // Implementation of prim algorithm, returns an undirected minimum spanning tree
    Graph Algorithms::prim(Graph& g) {
        int numVertices = g.getVerticsCounter();
    
        // Initializing a PriorityQueue with the size of the number of vertecies in the graph
        PriorityQueue pq(numVertices);
    
        // Track the minimum weight of edges connecting vertices to the MST
        int* minEdge = new int[numVertices];
        // Track the parent vertex for each vertex in the MST
        int* parent = new int[numVertices];
        // Track whether a vertex is in the MST or not
        bool* inMST = new bool[numVertices];

        // Graph to store the resulting MST
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
    
            // Looping through all neighbors of u
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
    
        // Add edges to MST based on the parent array using addEdge for undirected edges
        for (int v = 1; v < numVertices; ++v) {
            int u = parent[v];
            if (u != -1) {
                // Add undirected edge (u, v) with the weight of minEdge[v] to the MST
                mst.addEdge(u, v, minEdge[v]); 
            }
        }
    
        // Clean up dynamically allocated memory
        delete[] minEdge;
        delete[] inMST;
        delete[] parent;
    
        return mst;
    }
    


    // Implementation of kruskal algorithm, returns an undirected minimum spanning tree
    Graph Algorithms::kruskal(Graph& g) {
        int V = g.getVerticsCounter();
        UnionFind uf(V); // Creating UnionFind needed for the algorithm
        Graph mst(V); // Graph to store the resulting MST


        Edge* edges = new Edge[V * (V - 1) / 2]; // Maximum possible edges in an undirected graph
        int edgeCount = 0;

        // 'Collect' all edges from the graph
        for (int u = 0; u < V; ++u) {
            neighborVertic* neighbors = g.getNeighborsList()[u];
            int neighborCount = g.getNeighborsCounter()[u];

            // Looping through all the vertex neighbors
            for (int i = 0; i < neighborCount; ++i) {
                int v = neighbors[i].id;
                int weight = neighbors[i].weight;

                if (u < v) {  // Avoid duplicate edges in undirected graph
                    edges[edgeCount++] = {u, v, weight};
                }
            }
        }

        // Sort edges by weight
        sortEdges(edges, edgeCount);

        // Process edges and build the MST
        for (int i = 0; i < edgeCount; ++i) {
            int u = edges[i].src;
            int v = edges[i].dest;

            if (uf.find(u) != uf.find(v)) {
                mst.addEdge(u, v, edges[i].weight);
                uf.unionSets(u, v);
            }
        }

        // Clean up dynamically allocated memory
        delete[] edges;
        return mst;
    }
    

    // Sorting edges using selection sort
    void Algorithms::sortEdges(Edge* edges, int edgeCount) {
        for (int i = 0; i < edgeCount - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < edgeCount; ++j) {
                if (edges[j].weight < edges[minIndex].weight) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                swap(edges[i], edges[minIndex]);
            }
        }
    }

    // Implementation of the swap function
    void Algorithms::swap(Edge &a, Edge &b) {
        Edge temp = a;
        a = b;
        b = temp;
    }
    
    



};