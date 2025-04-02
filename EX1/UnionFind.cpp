/*
Email: shanig7531@gmail.com
*/

#include "UnionFind.hpp"

// Constructor- Initializes the Union-Find data structure with a given size
UnionFind::UnionFind(int size) {
    this->size = size;
    parent = new int[size];
    rank = new int[size];
    
    for (int i = 0; i < size; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Destructor- Deallocates dynamically allocated memory
UnionFind::~UnionFind() {
    delete[] parent;
    delete[] rank;
}


// Find function- Finds the root of the set containing x with path compression
int UnionFind::find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}


// Union function- Merges two sets containing x and y using union by rank
void UnionFind::unionSets(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    // Union by rank- attach the smaller tree under the larger tree
    if (rootA != rootB) {
        // Union by rank
        if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA; // Make rootX the parent of rootY
        } else if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB; // Make rootY the parent of rootX
        } else {
            parent[rootB] = rootA; // Merge and increment rank if equal
            rank[rootA]++;
        }
    }
}
