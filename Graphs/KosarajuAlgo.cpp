#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
    Time Complexity : O(V + E), where V is the number of vertices and E is the number of edges. Each vertex and edge is processed exactly once in both DFS traversals.
    Auxiliary Space : O(V) for storing the visited array and stack.
*/
class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // DFS to fill stack with vertices based on finish time
    void fillOrder(int v, vector<bool>& visited, stack<int>& Stack) {
        visited[v] = true;

        for (int u : adj[v]){
            if (!visited[u]){
                fillOrder(u, visited, Stack);
            }
        }
        
        Stack.push(v);
    }

    // DFS on transposed graph
    void dfs(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int u : adj[v]){
            if (!visited[u]){
                dfs(u, visited);
            }
        }
    }

    // Transpose of the graph
    Graph getTranspose() {
        Graph graph(V);
        for (int v = 0; v < V; v++) {
            for (int u : adj[v]){
                graph.adj[u].push_back(v);
            }
        }
        return graph;
    }

    // Kosaraju’s main algorithm
    void printSCC() {
        stack<int> Stack;
        vector<bool> visited(V, false);

        // Step 1: Fill stack with finish times
        for (int i = 0; i < V; i++){
            if (!visited[i]){
                fillOrder(i, visited, Stack);
            }
        }

        // Step 2: Transpose the graph
        Graph graph = getTranspose();

        // Step 3: DFS on transposed graph in order of stack
        fill(visited.begin(), visited.end(), false);
        cout << "Strongly Connected Components : ";

        int numberOfSCC = 0;

        while (!Stack.empty()) {
            int node = Stack.top();
            Stack.pop();

            if (!visited[node]) {
                numberOfSCC++;

                cout << "{ ";
                graph.dfs(node, visited);
                cout << "} ";
            }
        }

        cout << endl << "Number of SCC : " << numberOfSCC << endl;
    }
};

int main() {
    Graph graph(5);
    graph.addEdge(1, 0);
    graph.addEdge(0, 2);
    graph.addEdge(2, 1);
    graph.addEdge(0, 3);
    graph.addEdge(3, 4);

    graph.printSCC();
    return 0;
}

/*
  Kosaraju’s Algorithm is a classic algorithm used for finding strongly connected components (SCCs) in a directed graph. 
  An SCC is a maximal subgraph where every vertex is reachable from every other vertex in the subgraph. 
  This algorithm is widely used in various applications such as finding cycles in a graph, circuit design, and network analysis.

  The algorithm works in two main phases:
    Perform a Depth-First Search (DFS) on the original graph and store the vertices in a stack according to their finish times.
    Transpose (reverse the edges) the graph and perform DFS using the vertices in the order defined by the stack to identify the SCCs.
*/