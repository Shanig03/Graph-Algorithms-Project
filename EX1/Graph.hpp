/*
Email: shanig7531@gmail.com
*/

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>

namespace graph {

    struct neighborVertic {
        int weight;
        int id;
    };

    class Graph {
        private: 
        int verticsCounter;
        neighborVertic** neighborsList;
        //count how many neighbors each vertics has. each index represent the vertic number, and the value inside is the num of neighbors for that vertic.
        int* neighborsCounter; 
        
        public:
        Graph(int numOfVertics); // Constractor
        Graph(const Graph& other); // Copy constractor

        ~Graph(); // Distractor

        void addEdge(int src, int dest, int weight); // This function gets 2 vertecies and weight and create a new edge.

        void addDirectedEdge(int src, int dest, int weight);  // Adds an undirected edge

        void removeEdge(int src, int dest); // This function gets 2 vertecies and remove an exicting edge.

        void print_graph() const; // Print the graph as a adj list

        int getVerticsCounter();

        int* getNeighborsCounter();

        neighborVertic** getNeighborsList();

        bool edgeCheck(int src, int dest) const;

        bool vertixCheck(int v);

        private:

        void addEdgeHelper(int src, int dest, int weight);
        
    };
}


#endif
