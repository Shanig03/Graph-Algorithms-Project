#include "UnionFind.hpp"

UnionFind::UnionFind(int size) {
    this->size = size;
    parent = new int[size];
    rank = new int[size];
    
    for (int i = 0; i < size; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

UnionFind::~UnionFind() {
    delete[] parent;
    delete[] rank;
}

int UnionFind::find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // Path compression
    }
    return parent[x];
}

void UnionFind::unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        // Union by rank
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}
