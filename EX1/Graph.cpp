#include <iostream>
#include "Graph.hpp"
#include <stdexcept>


namespace graph {

    Graph::Graph(int numOfVertics) {
        this->verticsCounter = numOfVertics;
        neighborsList = new neighborVertic*[numOfVertics];
        neighborsCounter = new int[numOfVertics];
        for (int i = 0; i < numOfVertics; ++i) {
            neighborsList[i] = nullptr;
            neighborsCounter[i] = 0;
        }
    }

    Graph::~Graph() {
        // Free each dynamically allocated adjacency list
        for (int i = 0; i < verticsCounter; ++i) {
            delete[] neighborsList[i];  // Free each neighbor array
        }
        
        // Free the array of pointers
        delete[] neighborsList;
        
        // Free the array storing neighbor counts
        delete[] neighborsCounter;
    }
    

    void Graph::addEdge(int src, int dest, int weight) {
        //i need to add 2 edges- one for each direction, because its a non directed edge.
        addEdgeHelper(src, dest, weight);
        addEdgeHelper(dest, src, weight);
    }

    void Graph::removeEdge(int src, int dest) {
        if (!edgeCheck(src, dest)) {
            std::cout << "Edge (" << src << ", " << dest << ") does not exist.\n";
            return;
        }
    
        // Remove `dest` from `src`'s adjacency list
        for (int i = 0; i < neighborsCounter[src]; ++i) {
            if (neighborsList[src][i].id == dest) {
                for (int j = i; j < neighborsCounter[src] - 1; ++j) {
                    neighborsList[src][j] = neighborsList[src][j + 1]; // Shift elements left
                }
                neighborsCounter[src]--;
                break;
            }
        }
    
        // Remove `src` from `dest`'s adjacency list (undirected graph)
        for (int i = 0; i < neighborsCounter[dest]; ++i) {
            if (neighborsList[dest][i].id == src) {
                for (int j = i; j < neighborsCounter[dest] - 1; ++j) {
                    neighborsList[dest][j] = neighborsList[dest][j + 1]; // Shift elements left
                }
                neighborsCounter[dest]--;
                break;
            }
        }
    
        std::cout << "Edge (" << src << ", " << dest << ") removed successfully.\n";
    }
    


    void Graph::print_graph() const {
        for (int i = 0; i < verticsCounter; ++i) {
            std::cout << "Vertex " << i << " has the following neighbors:\n";
    
            if (neighborsCounter[i] == 0) {
                std::cout << "  No neighbors\n";
            } else {
                for (int j = 0; j < neighborsCounter[i]; ++j) {
                    std::cout << "  → Neighbor: " << neighborsList[i][j].id
                              << " (Weight: " << neighborsList[i][j].weight << ")\n";
                }
            }
    
            std::cout << "--------------------------------\n";  // Formatting for clarity
        }
    }
    

    void Graph::addEdgeHelper(int src, int dest, int weight) {
        // Create a new list with size increased by 1
        neighborVertic* copiedList = new neighborVertic[neighborsCounter[src] + 1];
    
        // Copy the old list to the new one
        for (int i = 0; i < neighborsCounter[src]; ++i) {
            copiedList[i] = neighborsList[src][i];  // Copy elements properly
        }
    
        // Add the new edge
        copiedList[neighborsCounter[src]].id = dest;
        copiedList[neighborsCounter[src]].weight = weight;
    
        // Free the old memory **ONLY IF it's not NULL**
        if (neighborsList[src] != nullptr) {
            delete[] neighborsList[src];  // Free old list
        }
    
        // Assign the new list
        neighborsList[src] = copiedList;
    
        // Increase the counter
        neighborsCounter[src]++;
    }
    

    bool Graph::edgeCheck(int src, int dest) const {
        for (int i = 0; i < neighborsCounter[src]; ++i) {

            if (neighborsList[src][i].id == dest) {
                return true;
            }
        }
        return false;
    }

    
    
}

