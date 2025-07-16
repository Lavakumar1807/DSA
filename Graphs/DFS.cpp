#include<bits/stdc++.h>
using namespace std;

// DFS : Depth First Search
// Time Complexity : O(V + E)

void dfsUtil(int node,vector<vector<int>>& adj,vector<int>& dfs,vector<int>& visited){
    visited[node] = 1;
    dfs.push_back(node);
    
    for(auto n : adj[node]){
        if(!visited[n]){
            dfsUtil(n,adj,dfs,visited);
        }
    }
}

void DFS(int v,int start,vector<vector<int>>& adj){
  vector<int> visited(v,0);
  vector<int> dfs;

  dfsUtil(start,adj,dfs,visited);

  cout<<"DFS Travesal : ";
  int size = dfs.size();
  for(int i=0;i<size;i++){
    cout<<dfs[i]<<" ";
  }
  cout<<endl;
}

int main(){
    int n,e;
    cout<<"Enter number of Nodes : ";
    cin>>n;

    cout<<"Enter number of Edges : ";
    cin>>e;

    int start;
    cout<<"Enter starting node (0 to n-1) : ";
    cin>>start;

    vector<vector<int>> adj(n);
    cout<<"Enter edges : ";
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    DFS(n,start,adj);
    return 0;
}