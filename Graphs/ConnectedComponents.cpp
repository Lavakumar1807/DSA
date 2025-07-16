#include<bits/stdc++.h>
using namespace std;

int main(){
    // 0 - indexed graph
    int edges,nodes;
    cout<<"Enter number of Edges : ";
    cin>>edges;

    cout<<"Enter number of Nodes : ";
    cin>>nodes;

    cout<<"Enter edges (0 - indexed): ";
    vector<vector<int>> adjList(nodes);
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

   
    // For a graph having disconnected components, use the below template before going to traverse, else it will not visit all the nodes.
    vector<int> visited(nodes,0);
    for(int i=0;i<nodes;i++){
        if(!visited[i]){
            // Traversal
        }
    }
    return 0;
}