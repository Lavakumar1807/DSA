// Detect a cycle in an undirected graph using DFS

#include<bits/stdc++.h>
using namespace std;

bool detectCycle(int node,int parent,vector<vector<int>>& adj,vector<int>& visited){
   visited[node] = 1;
   
   for(auto adjacentNode : adj[node]){
      if(!visited[adjacentNode]){
         if(detectCycle(adjacentNode,node,adj,visited)){
            return true;
         }
      }else if(adjacentNode != parent){
        return true;
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
    
    vector<int> visited(n,0);

    bool detected = detectCycle(source,-1,adj,visited);
    if(detected) cout<<"A cycle has been detected in the graph"<<endl;
    else cout<<"NO cycle has been detected in the graph"<<endl;
    return 0;
}
