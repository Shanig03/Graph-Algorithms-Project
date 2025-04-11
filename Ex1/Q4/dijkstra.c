#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Function to find the vertex with minimum distance value, from the set of vertices not yet included in the shortest path tree
int minDistance(int dist[], bool sptSet[], int V)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[], int V)
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t\t %d\n", i, dist[i]);
}

// Function to implement Dijkstra's single source shortest path algorithm for a graph represented using an adjacency matrix
void dijkstra(int **graph, int V, int src)
{
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist, V);
}

// Driver's code
int main()
{
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    // Dynamically allocate memory for the graph (adjacency matrix)
    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        graph[i] = (int *)malloc(V * sizeof(int));

    printf("Enter the weights of the graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("Weight of edge between vertex %d and vertex %d (enter 0 if no edge): ", i, j);
            int temp;
            scanf("%d", &temp);
            if (temp < 0) {
                printf("Cant enter a negative weight\n");
                //for (int k = 0; k < V; k++){
                //    free(graph[k]);
                //    free(graph);
                //}
                exit(1);// return 1 ??
            }
            graph[i][j] = temp;
        }
    }

    dijkstra(graph, V, 0);

    for (int i = 0; i < V; i++)
        free(graph[i]);
    free(graph);

    return 0;
}
