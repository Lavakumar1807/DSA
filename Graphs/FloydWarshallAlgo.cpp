#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(v^3) , where V is the number of nodes present in the graph
void FloydWarshall(int nodes,int edges,vector<vector<int>>& input){
    vector<vector<int>> distance(nodes,vector<int>(nodes,1e9));
    
    for(int i=0;i<nodes;i++){
        distance[i][i] = 0;
    }

    for(int i=0;i<edges;i++){
        int u = input[i][0];
        int v = input[i][1];
        int weight = input[i][2];

        distance[u][v] = min(distance[u][v],weight);
        //  distance[v][u] = min(distance[v][u],weight); // Add this for undirected graph
    }

    for(int via = 0;via < nodes;via++){
        for(int i = 0;i < nodes;i++){
            for(int j = 0;j < nodes;j++){
                distance[i][j] = min(distance[i][j],distance[i][via] + distance[via][j]);
            }
        }
    }

    for(int i=0;i<nodes;i++){
       if(distance[i][i] < 0){
          cout<<"A negative cycle is detected"<<endl;
          return;
       }
    }

    for(int u=0;u<nodes;u++){
        for(int v=0;v<nodes;v++){
             cout<<"The shortest path distance between node u and node v are : "<<distance[u][v]<<endl;
        }
    }
}

int main(){
    int edges, nodes;
    cout << "Enter number of edges  : ";
    cin >> edges;

    cout << "Enter number of nodes : ";
    cin >> nodes;

    int source;
    cout << "Enter source node (0 to nodes-1) : ";
    cin >> source;

    // [node1,nod2,edgeWeight];
    // Here graph is Directed graph
    cout << "Enter edges [node1,nod2,edgeWeight] : " << endl;
    vector<vector<int>> input(edges, vector<int>(3));
    for (int i = 0; i < edges; i++)
    {
        cin >> input[i][0] >> input[i][1] >> input[i][2];
    }

    FloydWarshall(nodes,edges,input);
    return 0;
}

/*
  Floyd Warshall Algorithm:

  The Floyd–Warshall algorithm works by maintaining a two-dimensional array that represents the distances between nodes.
  Initially, this array is filled using only the direct edges between nodes.
  Then, the algorithm gradually updates these distances by checking if shorter paths exist through intermediate nodes.

  This algorithm works for both the directed and undirected weighted graphs and can handle graphs with both positive and negative weight edges.
  Suppose we have a graph dist[][] with V vertices from 0 to V-1.
  Now we have to evaluate a dist[][] where dist[i][j] represents the shortest path between vertex i to j.

  Let us assume that vertices i to j have intermediate nodes.
  The idea behind Floyd Warshall algorithm is to treat each and every vertex k from 0 to V-1 as an intermediate node one by one.
  When we consider the vertex k, we must have considered vertices from 0 to k-1 already.
  So we use the shortest paths built by previous vertices to build shorter paths with vertex k included.
*/