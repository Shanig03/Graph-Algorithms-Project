/*
* Email: shanig7531@gmail.com
*/

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <iostream>
#include "Graph.hpp"

namespace graph {

    class Algorithms {
        
        public:

        static Graph BFS(Graph& graph, int startVertex);

        Graph DFS(Graph g, int src);

        Graph dijkstra(Graph g, int src);

        Graph prim(Graph g);
        
        Graph kruskal(Graph g);

    };

};



#endif