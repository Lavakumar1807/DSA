// Topological Sort using DFS

#include<bits/stdc++.h>
using namespace std;

void TopoSort(int node,vector<vector<int>>& adj,vector<int>& visited,stack<int>& st){
    visited[node] = 1;
    
    for(auto adjNode : adj[node]){
        if(!visited[adjNode]){
            TopoSort(adjNode,adj,visited,st);
        }
    }

    st.push(node);
}

int main(){
    int n,e;
    cout<<"Enter number of Nodes : ";
    cin>>n;

    cout<<"Enter number of Edges : ";
    cin>>e;

    cout<<"Enter edges : ";
    vector<vector<int>> adj(n);
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    vector<int> visited(n,0);
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            TopoSort(i,adj,visited,st);
        }
    }

    cout<<"Topological sort Order : ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}

/*
  Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u-->v, vertex u comes before v in the ordering.
  Note: Topological Sorting for a graph is not possible if the graph is not a DAG.
*/