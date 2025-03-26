/*
Email: shanig7531@gmail.com
*/

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <iostream>
#include "Graph.hpp"

namespace graph {

    class Algorithms {

        public:

        static Graph BFS(Graph& graph, int startVertex);

        static Graph DFS(Graph& graph, int startVertex);

        static void dfsVisit(Graph& graph, int current, bool* visited, Graph& dfsTree);

        static Graph dijkstra(Graph& g, int src);

        Graph prim(Graph g);
        
        Graph kruskal(Graph g);



    };

};



#endif