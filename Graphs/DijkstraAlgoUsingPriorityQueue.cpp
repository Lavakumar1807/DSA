// Dijkstra Algorithm using Prioriy Queue

#include <bits/stdc++.h>
using namespace std;

void Dijkstra(int nodes, int source, vector<vector<int>> &input)
{
    vector<vector<pair<int, int>>> adj(nodes);
    for (auto it : input)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(nodes, 1e9);

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto adjPair : adj[node])
        {
            int edgeWeight = adjPair.second;
            int adjNode = adjPair.first;
            if (edgeWeight + distance < dist[adjNode])
            {
                dist[adjNode] = edgeWeight + distance;
                pq.push({dist[adjNode], adjNode});
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

/*
 Time Complexity ==> O(Edges*log(Vertices)) ==> O(Elog(V));
 Proof : O(V*( log(heapSize) + numberofAdjacentNode*log(heapSize) ))
         O(V*log(heapSize)*(numberofAdjacentNode + 1)); // worst case numberofAdjacentNode = V - 1
         O(V*log(heapSize)*(V)) // worst case heap size = V*V
         O(V*V*log(V*V))
         O(2*V*V*log(V))
         O(E*log(V))  // V*V == E at worst case

 In Dijkstra's Algorithm, the goal is to find the shortest distance from a given source node to all other nodes in the graph.
 As the source node is the starting point, its distance is initialized to zero. From there, we iteratively pick the unprocessed node with the minimum distance from the source, this is where a min-heap (priority queue) or a set is typically used for efficiency.
 For each picked node u, we update the distance to its neighbors v using the formula: dist[v] = dist[u] + weight[u][v], but only if this new path offers a shorter distance than the current known one.
 This process continues until all nodes have been processed

*/