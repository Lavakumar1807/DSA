#include<bits/stdc++.h>
using namespace std;

// BFS : Breadth First Search
// Time Complexity : O(V + E)
void BFS(int nodes,int start,vector<vector<int>>& adj){
    vector<int> visited(nodes,0);
    vector<int> bfs;
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        bfs.push_back(node);

        for(auto adjNode : adj[node]){
            if(!visited[adjNode]){
                visited[adjNode] = 1;
                q.push(adjNode);
            }
        }
    }

    cout<<"BFS Traversal : ";
    int size = bfs.size();
    for(int i=0;i<size;i++){
        cout<<bfs[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int nodes,edges;
    cout<<"Enter number of Nodes : ";
    cin>>nodes;

    cout<<"Enter number of Edges : ";
    cin>>edges;

    int start;
    cout<<"Enter starting node (0 to nodes-1) : ";
    cin>>start;

    vector<vector<int>> adj(nodes);
    cout<<"Enter edges : ";
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    BFS(nodes,start,adj);
    return 0;
}

/*
   Breadth First Search (BFS)  is a fundamental  graph traversal algorithm.
   It begins with a node, then first traverses all its adjacent nodes. Once all adjacent are visited, then their adjacent are traversed. 
*/