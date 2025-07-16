// Dijkstra Algorithm using Set

#include <bits/stdc++.h>
using namespace std;

void Dijkstra(int nodes,int source,vector<vector<int>>& input){
    vector<vector<pair<int, int>>> adj(nodes);
    for (auto it : input)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    set<pair<int,int>> st;
    vector<int> dist(nodes, 1e9);
    
    dist[source] = 0;
    st.insert({0,source});

    while(!st.empty()){
        pair<int,int> firstPair = *(st.begin());
        int distance = firstPair.first;
        int node = firstPair.second;
        st.erase(firstPair);

        for(auto adjPair : adj[node]){
           int edgeWeight = adjPair.second;
           int adjNode = adjPair.first;
           
           if(distance + edgeWeight < dist[adjNode]){
              if(dist[adjNode] != 1e9){
                st.erase({dist[adjNode],adjNode});
              }

              dist[adjNode] = distance + edgeWeight;
              st.insert({dist[adjNode],adjNode});
           }
        }
    }

    cout << "Shortest path distance of a node from the source node (node,shortest path distance) " << endl;
    for (int i = 0; i < nodes; i++)
    {
        cout << "[ " << i << " --> ";
        cout << dist[i] << " ]" << endl;
    }
    cout << endl;
}

int main()
{
    int edges, nodes;
    cout << "Enter number of edges  : ";
    cin >> edges;

    cout << "Enter number of nodes : ";
    cin >> nodes;

    int source;
    cout << "Enter source node (0 to nodes-1) : ";
    cin >> source;

    // [node1,nod2,edgeWeight];
    cout << "Enter edges [node1,nod2,edgeWeight] : " << endl;
    vector<vector<int>> input(edges, vector<int>(3));
    for (int i = 0; i < edges; i++)
    {
        cin >> input[i][0] >> input[i][1] >> input[i][2];
    }

    Dijkstra(nodes, source, input);
    return 0;
}