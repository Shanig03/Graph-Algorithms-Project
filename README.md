# Graph Algorithms Project

## Overview
Email: shanig7531@gmail.com


This project implements a graph data structure using adjacency lists, along with various graph algorithms. The implementation is based on arrays instead of standard library containers like `vector` or `list`. The key algorithms included are:

- Breadth-First Search (BFS)
- Depth-First Search (DFS)
- Dijkstra's Shortest Path Algorithm
- Prim's Minimum Spanning Tree Algorithm
- Kruskal's Minimum Spanning Tree Algorithm (using Union-Find)

## Graph Implementation

The `Graph` class provides a way to represent a weighted graph using adjacency lists stored as dynamically allocated arrays.

### Features:

- **Graph Constructor:** Initialize a graph with a specified number of vertices.
- **Edge Management:** Add and remove both directed and undirected edges by using the functions `addEdge`, `addDirectedEdge` and `removeEdge`.
- **Graph Traversal:** Print the adjacency list representation of the graph by using the function `printGraph`.
- **Memory Management:** Proper deallocation of dynamically allocated arrays to prevent memory leaks.

#### - Graph Class Usage Example In Main.

### - For Implementing the Algorithms I Also Implemented This Classes:
 `Queue` , `PriorityQueue` and `UnionFind`. Each one of them is implemented in a different file with a fitting name.

## Algorithms Implementation

The `Algorithms` class provides various graph algorithms:

### 1. **Breadth-First Search (BFS)**

- Constructs a directed BFS tree from a starting vertex.
- Utilizes a custom `Queue` implementation.

### 2. **Depth-First Search (DFS)**

- Constructs a directed DFS tree.
- Uses recursion to explore all reachable vertices.

### 3. **Dijkstra’s Algorithm**

- Computes the shortest path tree from a single source vertex.
- Utilizes a custom `PriorityQueue` implementation.
- Does not support negative weight edges.

### 4. **Prim’s Algorithm**

- Constructs a Minimum Spanning Tree (MST) using a priority queue.
- Adds edges to the MST based on minimum weight.

### 5. **Kruskal’s Algorithm**

- Constructs a Minimum Spanning Tree (MST) using edge sorting and the Union-Find data structure.
- The `UnionFind` class provides efficient set operations.

###  - Algorithms Class Usage Example In Main.


## Testing

This project is tested using **Doctest**, ensuring correctness of implemented functionalities.
The tests implementatin is in the `Test.cpp` file.

## Makefile Usage

The project includes a `Makefile` that runs the project using the clang++ compiler with the following commands:

- `make Main` - Compiles the main program.
- `make test` - Compiles and runs the test suite using Doctest.
- `make valgrind` - Runs the program with Valgrind for memory leak detection.
- `make clean` - Removes all compiled files.

To compile and run the main program:

```sh
make Main
./Main
```

To run tests:

```sh
make test
```

To check for memory leaks with Valgrind:

```sh
make valgrind
```
To removes all compiled files :

```sh
make clean
```
## Summary

This project demonstrates a dynamic memory-based approach to implementing graphs and graph algorithms in C++. It avoids STL containers in favor of arrays. It also include graphs and algorithms demonstratin and testing.

