#include <iostream>
#include <vector>

using namespace std;

int timer = 1;
void TarjanDFS(int node,int parent,vector<int>& visited,
    vector<vector<int>>& adj,vector<int>& timeIn,vector<int>& lowTime,vector<vector<int>>& bridges){
    
     visited[node] = 1;
     timeIn[node] = timer;
     lowTime[node] = timer;
     timer++;

     for(auto adjNode : adj[node]){
        if(adjNode == parent) continue;
        if(visited[adjNode] == 0){
            TarjanDFS(adjNode,node,visited,adj,timeIn,lowTime,bridges);
            lowTime[node] = min(lowTime[node],lowTime[adjNode]);

            if(timeIn[node] < lowTime[adjNode]){
                bridges.push_back({node,adjNode});
            }
        }else{
            lowTime[node] = min(lowTime[node],lowTime[adjNode]);
        }
     }
}

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

    vector<int> visited(nodes,0);
    vector<int> timeIn(nodes,0); // The time at which the DFS first visits the node (entry time).
    vector<int> lowTime(nodes,0); // Lowest Reachable Time ( minimum of all adjacent nodes lowTimes except parent )
    vector<vector<int>> bridges;

    for (int i = 0; i < nodes; i++) {
      if (!visited[i]) {
        TarjanDFS(i, -1, visited, adjList, timeIn, lowTime, bridges);
      }
    }

    cout << "Bridges : ";
    for(auto bridge : bridges){
        int u = bridge[0];
        int v = bridge[1];
        cout << "{ " << u <<"--" << v << " } ";
    }
    return 0;
}

/*
   Time Complexity : O(V + E) , where V is number of vertices and E is number of edges
   Bridge : An edge (𝑢,𝑣) is a bridge if removing it disconnects the graph — meaning there is no longer a path between u and 𝑣, or it causes some other vertices to become unreachable.
*/