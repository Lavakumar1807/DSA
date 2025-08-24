#include <bits/stdc++.h>
using namespace std;

// Using Kahn's Algorithm
void detectCycle(int nodes,vector<vector<int>>& adj){
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

    int count = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        count++;

        for(int adjNode : adj[node]){
            indegree[adjNode]--;
            if(indegree[adjNode] == 0){
                q.push(adjNode);
            }
        }
    }

    if(count != nodes){
        cout << "Cycle Detected!!" << endl;
    }else{
        cout << "No Cycle Detected" << endl;
    }
}


int main(){
    int nodes,edges;
    cout<<"Enter number of Nodes : ";
    cin>>nodes;

    cout<<"Enter number of Edges : ";
    cin>>edges;

    cout<<"Enter edges u --> v (0 to nodes-1): ";
    vector<vector<int>> adj(nodes);
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    detectCycle(nodes,adj);
    return 0;
}