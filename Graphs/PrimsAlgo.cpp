#include<bits/stdc++.h>
using namespace std;

void Prims(int v,int start,vector<vector<int>> & edges){
    vector<vector<pair<int,int>>> adj(v); // {node,weight}
    for(auto e : edges){
        adj[e[0]].push_back({e[1],e[2]});
        adj[e[1]].push_back({e[0],e[2]});
    }

    // NOTE : Storing Parent is not necessary.
    // {weight,{node,parent}}
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    vector<pair<int,int>> mst;
    vector<int> visited(v,0);

    int edgeSum = 0;
    pq.push({0,{start,-1}});

    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();

        pair<int,int> nodePair = top.second;
        int node = nodePair.first;
        int parent = nodePair.second;
        int weight = top.first;

        if(visited[node]) continue;

        if(parent != -1)
            mst.push_back({parent, node});

        edgeSum += weight;
        visited[node] = 1;

        for(auto adjPair : adj[node]){
            int adjNode = adjPair.first;
            int edgeWeight = adjPair.second;
            if(!visited[adjNode]){
                pq.push({edgeWeight,{adjNode,node}});
            }
        }
    }

    cout<<"Minimum Spanning Tree Edges : ";
    for(auto e : mst){
        cout<<" ("<<e.first<<"--"<<e.second<<") ";
    }
    cout<<endl;

    cout<<"EdgeSum : "<<edgeSum<<endl;
}

int main(){
    int V,E;
    cout<<"Enter number of edges : ";
    cin>>E;

    cout<<"Enter number of vertices : ";
    cin>>V;

    vector<vector<int>> edges(E,vector<int>(3));
    cout<<"Enter edges (node,node,weight) : ";
    for(int i=0;i<E;i++){
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }

    int start;
    cout<<"Enter start node (0,V - 1): ";
    cin>>start;

    Prims(V,start,edges);
    return 0;
}