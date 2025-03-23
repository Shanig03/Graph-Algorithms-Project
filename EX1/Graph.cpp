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

    }

    void Graph::addEdge(int src, int dest, int weight) {
        //i need to add 2 edges- one for each direction, because its a non directed edge.
        addEdgeHelper(src, dest, weight);
        addEdgeHelper(dest, src, weight);
    }

    void Graph::removeEdge(int src, int dest) {
        if (!edgeCheck(src, dest)) {
            throw std::runtime_error("There is no such edge in the graph");
        }

        int index = -1;
        for (int i = 0; i < neighborsCounter[src]; ++i){
            if (dest == neighborsList[src][i].id) {
                index = i;
                break;
            }
        }
        // checking that this edge does excist in the graph
        if (index == -1){
            return;
        }

        for (int i = index; i < neighborsCounter[src] - 1; ++i) {
            // moving the neighbors backward and "running over" the edge the need to be deleted
            neighborsList[src][i] = neighborsList[src][i + 1]; 
        }

        // decreasing the counter in the fitting index 
        neighborsCounter[src]--;

        // for the undirected edge
        int index = -1;
        for (int i = 0; i < neighborsCounter[dest]; ++i){
            if (dest == neighborsList[dest][i].id) {
                index = i;
                break;
            }
        }
        // checking that this edge does excist in the graph
        if (index == -1){
            return;
        }

        for (int i = index; i < neighborsCounter[dest] - 1; ++i) {
            // moving the neighbors backward and "running over" the edge the need to be deleted
            neighborsList[dest][i] = neighborsList[dest][i + 1]; 
        }

        // decreasing the counter in the fitting index 
        neighborsCounter[dest]--;
    }


    void Graph::print_graph() const {
        for (int i = 0; i < verticsCounter; ++i){
            std:: cout << "The neighbors for vertic " << i << " are: " << std:: endl;
            for (int j = 0; j < neighborsCounter[i]; ++j) {
                std:: cout << neighborsList[i][j].id << "\nwith weight of: " 
                           << neighborsList[i][j].weight << std:: endl;
            }

        }

    }


    void Graph::addEdgeHelper(int src, int dest, int weight) {
        //creating a new list in the size of the current one plus one
        neighborVertic* coppiedList = new neighborVertic[neighborsCounter[src] + 1];

        // copy the old list to the new one
        for (int i = 0; i < neighborsCounter[src]; ++i) {
            coppiedList[i] = neighborsList[src][i];
        }

        //adding the new edge to the new list
        coppiedList[neighborsCounter[src]].id = dest;
        coppiedList[neighborsCounter[src]].weight = weight;

        //deleting the old list
        delete[] neighborsList[src];

        //putting the updated list instead of the old one
        neighborsList[src] = coppiedList;

        //increasing the counter in the fitting index 
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

