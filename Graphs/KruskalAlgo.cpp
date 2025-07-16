#include<bits/stdc++.h>
using namespace std;

class DSU{
   vector<int> size;
   vector<int> parent;
public : 
    DSU(int nodes){
      size.resize(nodes,1);
      parent.resize(nodes);

      for(int i = 0;i < nodes;i++){
        parent[i] = i;
      }
    }

    int findRoot(int node){
        if(parent[node] == node){
            return node;
        }

        return parent[node] = findRoot(parent[node]);
    }

    void unionBySize(int u,int v){
        int uRoot = findRoot(u);
        int vRoot = findRoot(v);

        if(uRoot == vRoot) return;

        if(size[uRoot] < size[vRoot]){
            parent[uRoot] = vRoot;
            size[vRoot] += size[uRoot];
        }else{
            parent[vRoot] = uRoot;
            size[uRoot] += size[vRoot];
        }
    }
};

bool comparator(vector<int> &a,vector<int> &b){
    if(a[2] < b[2]) return true;
    return false;
}

void Kruskal(int nodes,vector<vector<int>>& edges){
    // Sort all the edges in increasing order of weights
    sort(edges.begin(),edges.end(),comparator);

    DSU ds(nodes);
    int edgeSum = 0;
    vector<vector<int>> mst;

    for(auto e : edges){
        int u = e[0];
        int v = e[1];
        int weight = e[2];

        if(ds.findRoot(u) != ds.findRoot(v)){
            ds.unionBySize(u,v);
            edgeSum += weight;
            
            mst.push_back({u, v, weight});
        }
    }

    cout << "The edge sum of the minimum spanning tree : " << edgeSum << endl;

    cout << "Edges in MST : ";
    for(auto e : mst){
      cout << "(" << e[0] << " - " << e[1] << " : " << e[2] << ") ";
    }
    cout << endl;
}

int main(){
    int nodes,e;
    cout << "Enter number of nodes  : ";
    cin >> nodes;

    cout << "Enter number of edges : ";
    cin >> e;

    vector<vector<int>> edges(e,vector<int>(3));
    cout << "Enter edges  (0 to nodes-1) :: (u, v, weight): " << endl;
    for(int i = 0;i < e;i++){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    Kruskal(nodes,edges);
    return 0;
}