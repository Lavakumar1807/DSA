#include<bits/stdc++.h>
using namespace std;

// Time complexity : O(V*E) , where V ==> Number of vertices in the graph and E ==> Number of edges in the graph

void BellmanFord(int V,int source,vector<vector<int>>& input){
    vector<int> distance(V,1e9);
    distance[source] = 0;

    for(int i=0;i<V-1;i++){
        for(auto it : input){
            int u = it[0];
            int v = it[1];
            int weight = it[2];

            if(distance[u] != 1e9 && distance[u] + weight < distance[v]){
                distance[v] = distance[u] + weight;
            }
        }
    }

    // Iterating Last time (V th) to check negative cycle in the graph
    for(auto it : input){
        int u = it[0];
        int v = it[1];
        int weight = it[2];

        if(distance[u] != 1e9 && distance[u] + weight < distance[v]){
            cout<<"There is a negative cycle in the graph"<<endl;
            return;
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
    cout << "Enter edges [node1,nod2,edgeWeight] : " << endl;
    vector<vector<int>> input(edges, vector<int>(3));
    for (int i = 0; i < edges; i++)
    {
        cin >> input[i][0] >> input[i][1] >> input[i][2];
    }

    BellmanFord(nodes, source, input);
    return 0;
}

/*
 Bellman-Ford is a single source shortest path algorithm.
 It effectively works in the cases of negative edges and is able to detect negative cycles as well. It works on the principle of relaxation of the edges.

 Principle of Relaxation of Edges :
        Relaxation means updating the shortest distance to a node if a shorter path is found through another node. For an edge (u, v) with weight w:
        If going through u gives a shorter path to v from the source node (i.e., distance[v] > distance[u] + w), we update the distance[v] as distance[u] + w.
        In the bellman-ford algorithm, this process is repeated (V - 1) times for all the edges.
 Detection of a Negative Weight Cycle
 We need (V - 1) relaxations of all the edges to achieve single source shortest path.
 If one additional relaxation (Vth) for any edge is possible, it indicates that some edges with overall negative weight has been traversed once more.
 This indicates the presence of a negative weight cycle in the graph.

==> Why Relaxing Edges (V - 1) times gives us Single Source Shortest Path?
    A shortest path between two vertices can have at most (V - 1) edges.
    It is not possible to have a simple path with more than (V - 1) edges (otherwise it would form a cycle).
    Therefore, repeating the relaxation process (V - 1) times ensures that all possible paths between source and any other node have been covered.
*/