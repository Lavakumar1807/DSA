#include<bits/stdc++.h>
using namespace std;

// Union by size

class DSU{
    vector<int> size;
    vector<int> parent;
public :
    DSU(int n){
        size.resize(n,1);
        parent.resize(n);
        
        for(int i = 0;i < n;i++){
            parent[i] = i;
        }
    }

    int findRoot(int node){
        if (parent[node] == node){
            return node;
        }

        return findRoot(parent[node]); 
    }

    void unionBySize(int u,int v){
        int uRoot = findRoot(u);
        int vRoot = findRoot(v);

        if(uRoot == vRoot) return;

        if(size[uRoot] < size[vRoot]){
            parent[uRoot] = vRoot;
            size[vRoot] = size[vRoot] + size[uRoot];
        }else{
            parent[vRoot] = uRoot;
            size[uRoot] = size[uRoot] + size[vRoot];
        }
    }
};

class DSUWithPathCompression{
    vector<int> size;
    vector<int> parent;
public : 
    DSUWithPathCompression(int n){
        size.resize(n,1);
        parent.resize(n);

        for(int i = 0;i < n;i++){
            parent[i] = i;
        }
    }

    int findRoot(int node){
        if(parent[node] == node){
            return node;
        }

        return parent[node] = findRoot(parent[node]); // Path compression
    }

    void unionBySize(int u,int v){
        int uRoot = findRoot(u);
        int vRoot = findRoot(v);

        if(uRoot == vRoot) return;

        if(size[uRoot] < size[vRoot]){
            parent[uRoot] = vRoot;
            size[vRoot] = size[vRoot] + size[uRoot];
        }else{
            parent[vRoot] = uRoot;
            size[uRoot] = size[uRoot] + size[vRoot];
        }
    }
};

int main(){
    DSUWithPathCompression dsu(7);  // Nodes from 0 to 6

    dsu.unionBySize(1, 2);
    dsu.unionBySize(2, 3);
    dsu.unionBySize(4, 5);
    dsu.unionBySize(6, 5);
    dsu.unionBySize(3, 5); 

    if (dsu.findRoot(1) == dsu.findRoot(6)) {
        cout << "1 and 6 belong to the same set\n";
    } else {
        cout << "1 and 6 do not belong to the same set\n";
    }

    return 0;
}

/*
=> Union by Size :
    We use an array of integers called size[]. The size of this array is the same as the parent array Parent[]. 
    If i is a representative of a set, size[i] is the number of the elements in the tree representing the set. 
    Now we are uniting two trees (or sets), let’s call them left and right, then in this case it all depends on the size of left and the size of right tree (or set).

    If the size of left is less than the size of right, then it’s best to move left under right and increase size of right by size of left. 
    In the same way, if the size of right is less than the size of left, then we should move right under left and increase size of left by size of right.
    If the sizes are equal, it doesn’t matter which tree goes under the other.

    -- Each set keeps track of its size (number of elements).
    -- When merging two sets, attach the smaller set under the larger one.
    -- This keeps the tree shallow and efficient.

    =>Time complexity: O(n) for creating n single item sets. The two techniques -path compression with the union by rank/size, the time complexity will reach nearly constant time. 
                       It turns out, that the final amortized time complexity is O(α(n)), where α(n) is the inverse Ackermann function, which grows very steadily.
    =>Space complexity: O(n) because we need to store n elements in the Disjoint Set Data Structure.
*/