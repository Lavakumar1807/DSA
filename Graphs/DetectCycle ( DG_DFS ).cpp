// Detect a cycle in a directed graph using DFS
#include<bits/stdc++.h>
using namespace std;

bool detectCycle(int node,vector<vector<int>>& adj,vector<int>& visited,vector<int>& pathVisited){
    visited[node] = 1;
    pathVisited[node] = 1;

    for(auto adjacentNode : adj[node]){
        if(!visited[adjacentNode]){
            if(detectCycle(adjacentNode,adj,visited,pathVisited)){
                return true;
            }
        }else if(pathVisited[adjacentNode]){
            return true;
        }
    }

    pathVisited[node] = 0;
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
    }
    
    vector<int> visited(n,0);
    vector<int> pathVisited(n,0);

    bool detected = false;
    for(int i=0;i<n;i++){
        if(detectCycle(i,adj,visited,pathVisited)){
            detected = true;
            break;
        } 
    }

    if(detected) cout<<"A cycle has been detected in the graph"<<endl;
    else cout<<"NO cycle has been detected in the graph"<<endl;
    return 0;
}
