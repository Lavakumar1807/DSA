#include<bits/stdc++.h>
using namespace std;

// General Implementation of Disjoint set Union - Find Algorithm

class DSU{
    vector<int> parent;
public :
    DSU(int size){
        parent.resize(size);
        for(int i = 0;i < size;i++){
            parent[i] = i;
        }
    }

    // Find the Ultimate Parent (root) of the set
    int findRoot(int node){
        if(parent[node] == node){
            return node;
        }

        return findRoot(parent[node]);
    }

    void unionSets(int u ,int v){
        int uRoot = findRoot(u);
        int vRoot = findRoot(v);

        parent[uRoot] = vRoot;
    }

};

int main(){
    int size = 5;
    DSU example(size);

    example.unionSets(1,2);
    example.unionSets(3,4);

    if(example.findRoot(1) == example.findRoot(2)){
        cout << "node 1 and node 3 belong to same set" << endl;
    }else{
        cout << "node 1 and node 3 are not belong to same set" << endl;
    }

    return 0;
}

/*
  Two sets are called disjoint sets if they don't have any element in common. The disjoint set data structure is used to store such sets. It supports following operations:

    Merging two disjoint sets to a single set using Union operation.
    Finding representative of a disjoint set using Find operation.
    Check if two elements belong to same set or not. We mainly find representative of both and check if same.

=> Data Structures used are: 

    Array: An array of integers is called Parent[]. If we are dealing with N items, i'th element of the array represents the i'th item. 
    More precisely, the i'th element of the Parent[] array is the parent of the i'th item. These relationships create one or more virtual trees.

    Tree: It is a Disjoint set. If two elements are in the same tree, then they are in the same Disjoint set. 
    The root node (or the topmost node) of each tree is called the representative of the set. 
    There is always a single unique representative of each set. A simple rule to identify a representative is if 'i' is the representative of a set, then Parent[i] = i. 
    If i is not the representative of his set, then it can be found by traveling up the tree until we find the representative.

=> Find:
    The task is to find representative of the set of a given element. 
    The representative is always root of the tree. 
    So we implement find() by recursively traversing the parent array until we hit a node that is root (parent of itself).

=> Union: 
    The task is to combine two sets and make one. 
    It takes two elements as input and finds the representatives of their sets using the Find operation, and finally puts either one of the trees (representing the set) under the root node of the other tree.
*/