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
        Graph(int numOfVertics);

        ~Graph();

        void addEdge(int src, int dest, int weight);

        void removeEdge(int src, int dest);

        void print_graph() const;

        private:
        void addEdgeHelper(int src, int dest, int weight);
        
        bool edgeCheck(int src, int dest) const;
    };
}


#endif
