// Detect a cycle in an undirected graph using BFS

#include<bits/stdc++.h>
using namespace std;

bool detectCycle(int n,int s,vector<vector<int>>& adj){
    vector<int> visited(n,0);
    queue<pair<int,int>> q;
    q.push({s,-1});
    visited[s] = 1;

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;

        for(auto adjacentNode : adj[node]){
            if(!visited[adjacentNode]){
                q.push({adjacentNode,node});
                visited[adjacentNode] = 1;
            }else if(adjacentNode != parent){
                return true;
            }
        }
    }

    return false;
}

int main(){
    int n,e;
    cout<<"Enter number of nodes : ";
    cin>>n;

    cout<<"Enter number of edges : ";
    cin>>e;

    int source ;
    cout<<"Enter source : ";
    cin>>source;

    vector<vector<int>> adj(n);
    cout<<"Enter edges : ";
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bool detected = detectCycle(n,source,adj);
    if(detected) cout<<"A cycle has been detected in the graph"<<endl;
    else cout<<"NO cycle has been detected in the graph"<<endl;
    return 0;
}
