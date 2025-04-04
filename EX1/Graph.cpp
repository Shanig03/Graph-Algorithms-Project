/*
Email: shanig7531@gmail.com
*/

#include <iostream>
#include "Graph.hpp"
#include <stdexcept>


namespace graph {

    // Constractor for the Graph class
    Graph::Graph(int numOfVertics) {
        // Check if the input number is valid (not negative)
        if (numOfVertics < 0) {
            throw std::invalid_argument("Number of vertices must be greater than 0.");
        }
        this->verticsCounter = numOfVertics;
        neighborsList = new neighborVertic*[numOfVertics];
        neighborsCounter = new int[numOfVertics];
        for (int i = 0; i < numOfVertics; ++i) {
            neighborsList[i] = nullptr;
            neighborsCounter[i] = 0;
        }
    }


    // Copy constractor
    Graph::Graph(const Graph& other) {
        verticsCounter = other.verticsCounter;
        neighborsList = new neighborVertic*[verticsCounter];
        neighborsCounter = new int[verticsCounter];
    
        for (int i = 0; i < verticsCounter; ++i) {
            neighborsCounter[i] = other.neighborsCounter[i];
            if (neighborsCounter[i] > 0) {
                neighborsList[i] = new neighborVertic[neighborsCounter[i]];
                for (int j = 0; j < neighborsCounter[i]; ++j) {
                    neighborsList[i][j] = other.neighborsList[i][j];
                }
            } else {
                neighborsList[i] = nullptr;
            }
        }
    }

    
    // Distractor for the Graph class
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
    

    // Function to add a weighted edge to the graph
    void Graph::addEdge(int src, int dest, int weight) {
        // Check if the src or the dest vertecis does not exict in the graph
        if (!vertixCheck(src) || !vertixCheck(dest)) {
            std::cout << "One of the vertices does not exist in this graph" << std::endl;
            return;
        }
    
        // Ensure edge does not exist before adding (only check src to dest)
        if (edgeCheck(src, dest)) {
            std::cout << "This edge is already exist" << std::endl;
            return;
        }
    
        // Add the edge in both directions for an undirected graph
        addEdgeHelper(src, dest, weight);
        addEdgeHelper(dest, src, weight);
    }
    
    
    
    // Function for adding directed edge
    void Graph::addDirectedEdge(int src, int dest, int weight) {
        // Checking if the edge already exist
        if(edgeCheck(src, dest)){
            std:: cout << "This edge is already exist" << std::endl;
            return;
        }

        // Check if the src or the dest vertecis does not exict in the graph
        if (!vertixCheck(src) || !vertixCheck(dest)) {
            std:: cout << "One of the vertecies does not exict in this graph" << std::endl;
            return;
        }
        
        addEdgeHelper(src, dest, weight);
    }


    // Function for removing an edge
    void Graph::removeEdge(int src, int dest) {
        // Checking if the edge already exist
        if (!edgeCheck(src, dest)) {
            std::cout << "Edge (" << src << ", " << dest << ") does not exist.\n";
            return;
        }
    
        // Remove dest from src adjacency list
        for (int i = 0; i < neighborsCounter[src]; ++i) {
            if (neighborsList[src][i].id == dest) {
                for (int j = i; j < neighborsCounter[src] - 1; ++j) {
                    neighborsList[src][j] = neighborsList[src][j + 1]; // Shift elements left
                }
                neighborsCounter[src]--;
                break;
            }
        }
    
        // Remove src from dest adjacency list
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
    

    // Print the graph in a form of adj list
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
    
            std::cout << "--------------------------------\n";
        }
    }
    

    // Helper function to add an edge
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
    
        // Free the old memory only of it's not null.
        if (neighborsList[src] != nullptr) {
            delete[] neighborsList[src];  // Free old list
        }
    
        // Assign the new list
        neighborsList[src] = copiedList;
    
        // Increase the counter
        neighborsCounter[src]++;
    }
    

    // Checks whether the edge already exicest
    bool Graph::edgeCheck(int src, int dest) const {        
        for (int i = 0; i < neighborsCounter[src]; ++i) {
            if (neighborsList[src][i].id == dest) {
                return true;  // Edge exists
            }
        }
        return false; 
    }
    
    
    // Getter for verticsCounter
    int Graph::getVerticsCounter() {
        return Graph::verticsCounter;
    }

    // Getter for neighborsCounter
    int* Graph::getNeighborsCounter() {
        return neighborsCounter;
    }

    // Getter for neighborsList
    neighborVertic** Graph::getNeighborsList(){
        return neighborsList;
    }

    // Check if the vertix exict
    bool Graph::vertixCheck(int v){
        if (v < verticsCounter) {
            return true;
        }
        return false;
    }
    
    // Getter for numOfEdges only for undirected graph
    int Graph::getNumOfEdges() {
        int sum = 0;
        for (int i = 0; i < verticsCounter; ++i) {
            sum += neighborsCounter[i]; 
        }
        return sum / 2; // Since it's an undirected graph, each edge is counted twice
    }    
    
    
    
}

