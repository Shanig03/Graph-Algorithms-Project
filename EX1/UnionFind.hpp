/*
Email: shanig7531@gmail.com
*/

#ifndef UNIONFIND_HPP
#define UNIONFIND_HPP

class UnionFind {

    private:
    int* parent;
    int* rank;
    int size;

    
    public:
    UnionFind(int size); // Constractor
    
    ~UnionFind(); // Distractor


    int find(int x); // Find function with path compression to find the representative of a set
    
    void unionSets(int a, int b); // Union function with rank-based merging to combine two sets


};

#endif 
