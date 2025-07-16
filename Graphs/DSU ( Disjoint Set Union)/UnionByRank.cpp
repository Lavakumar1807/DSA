#include<bits/stdc++.h>
using namespace std;

// Union by rank

class DSU{
    vector<int> rank;
    vector<int> parent;
public : 
    DSU(int size){
        rank.resize(size,0);
        parent.resize(size);

        for(int i = 0;i < size;i++){
           parent[i] = i;
        }
    }

    int findRoot(int node){
        if(parent[node] == node){
            return node;
        }

        return findRoot(parent[node]);
    }

    void unionByRank(int u,int v){
        int uRoot = findRoot(u);
        int vRoot = findRoot(v);

        if (uRoot == vRoot) return;

        if(rank[uRoot] < rank[vRoot]){
            parent[uRoot] = vRoot;
        }else if(rank[uRoot] > rank[vRoot]){
            parent[vRoot] = uRoot;
        }else{
           parent[vRoot] = uRoot;
           rank[uRoot]++;
        }
    }
};

class DSUWithPathCompression{
    vector<int> rank;
    vector<int> parent;
public :
    DSUWithPathCompression (int size){
        rank.resize(size,0);
        parent.resize(size);

        for(int i = 0;i < size;i++){
            parent[i] = i;
        }
    }

    int findRoot(int node){
        if(parent[node] == node){
            return node;
        }
        
        return parent[node] = findRoot(parent[node]); // Path compression
    }

    void unionByRank(int u,int v){
        int uRoot = findRoot(u);
        int vRoot = findRoot(v);

        if(uRoot == vRoot) return;

        if(rank[uRoot] < rank[vRoot]){
            parent[uRoot] = vRoot;
        }else if(rank[uRoot] > rank[vRoot]){
            parent[vRoot] = uRoot;
        }else{
            parent[vRoot] = uRoot;
            rank[uRoot]++;
        }
    }
};

int main(){
    int size = 5;
    DSUWithPathCompression dsu(size);

    dsu.unionByRank(1,2);
    dsu.unionByRank(3,4);

    if(dsu.findRoot(1) == dsu.findRoot(3)){
        cout << "node 1 and node 3 belong to same set" << endl;
    }else{
        cout << "node 1 and node 3 are not belong to same set" << endl;
    }

    return 0;
}

/*
=> Union by Rank :

    We use an extra array of integers called rank[]. The size of this array is the same as the parent array Parent[]. 
    If i is a representative of a set, rank[i] is the rank of the element i.
    Now recall that in the Union operation, it doesn’t matter which of the two trees is moved under the other. 
    Now what we want to do is minimize the height of the resulting tree. 

    If we are uniting two trees (or sets), let’s call them left and right, then it all depends on the rank of left and the rank of right. 
    If the rank of left is less than the rank of right, then it’s best to move left under right, because that won’t change the rank of right (while moving right under left would increase the height). 
    In the same way, if the rank of right is less than the rank of left, then we should move right under left.
    If the ranks are equal, it doesn’t matter which tree goes under the other, but the rank of the result will always be one greater than the rank of the trees.

    Union by rank is a technique used in Disjoint Set Union (DSU) data structures to optimize the union operation. 
    It aims to minimize the height of the resulting tree when merging two sets, thus improving the efficiency of subsequent find operations. 
    In essence, it attaches the tree with the smaller rank (or depth) under the root of the tree with the larger rank.alignas

NOTE : Rank is not the exact height of the tree — it’s an estimate.
       It helps us decide which tree to attach to which during a union operation to keep the overall structure balanced.
       With path compression, actual height becomes even smaller, but rank remains as an efficient approximation.

    =>Time complexity: O(n) for creating n single item sets. The two techniques -path compression with the union by rank/size, the time complexity will reach nearly constant time. 
                       It turns out, that the final amortized time complexity is O(α(n)), where α(n) is the inverse Ackermann function, which grows very steadily.
    =>Space complexity: O(n) because we need to store n elements in the Disjoint Set Data Structure.
*/