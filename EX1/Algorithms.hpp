/*
Email: shanig7531@gmail.com
*/

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <iostream>
#include "Graph.hpp"
#include "PriorityQueue.hpp"

struct Edge {
    int src, dest, weight;
};

namespace graph {

    class Algorithms {

        public:

        static Graph BFS(Graph& graph, int startVertex);

        static Graph DFS(Graph& graph, int startVertex);

        static void dfsVisit(Graph& graph, int current, bool* visited, Graph& dfsTree);

        static Graph dijkstra(Graph& g, int src);

        static void relax(int u, int v, int weight, int* dist, int* parent, PriorityQueue& pq);

        static Graph prim(Graph& g);
        
        static Graph kruskal(Graph& g);

        static void sortEdges(Edge* edges, int edgeCount);

        static void swap(Edge &a, Edge &b); 





    };

};



#endif