#include <bits/stdc++.h>
using namespace std;

int main(){
    int edges,nodes;
    cout<<"Enter number of Edges : ";
    cin>>edges;

    cout<<"Enter number of Nodes : ";
    cin>>nodes;

    // Using Adjacency List for an Undirected Graph (0 indexed graph )
    cout<<"Enter edges : ";
    vector<vector<int>> adjList(nodes);
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i=0;i<nodes;i++){
        cout<<i<<" : ";
        int size = adjList[i].size();
        for(int j=0;j<size;j++){
            cout<<adjList[i][j]<<" ";
        }
        cout<<endl;
    }

    /*
    //Using Adjacency Matrix for an Undirected Graph (0 indexed graph)
    cout<<"Enter edges : ";
    vector<vector<int>> adjMatrix(nodes,vector<int>(nodes,0));
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            cout<<adjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }*/

    return 0;
}