// Topological Sort using BFS

#include<bits/stdc++.h>
using namespace std;

void KahnAlgo(int nodes,vector<vector<int>>& adj){
    vector<int> indegree(nodes,0);
    for(int i=0;i<nodes;i++){
        for(auto node : adj[i]){
            indegree[node]++;
        }
    }

    queue<int> q;
    for(int i=0;i<nodes;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        topo.push_back(node);

        for(auto adjNode : adj[node]){
            indegree[adjNode]--;
            if(indegree[adjNode] == 0){
                q.push(adjNode);
            }
        }
    }

    cout<<"Topological sort Order : ";
    int size = topo.size();
    for(int i=0;i<size;i++){
        cout<<topo[i]<<' ';
    }
    cout<<endl;
}

int main(){
    int nodes,edges;
    cout<<"Enter number of Nodes : ";
    cin>>nodes;

    cout<<"Enter number of Edges : ";
    cin>>edges;

    cout<<"Enter edges u --> v: ";
    vector<vector<int>> adj(nodes);
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    KahnAlgo(nodes,adj);
    return 0;
}
/*
   Kahn’s Algorithm works by repeatedly finding vertices with no incoming edges, removing them from the graph, and updating the incoming edges of the vertices connected from the removed removed edges.
   This process continues until all vertices have been ordered.
*/