#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <climits>
#include <stack>
#include <set>
using namespace std;

// Graph Algorithms: BFS and DFS
void bfsGraph(vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

void dfsUtil(int v, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";
    for (int u : adj[v]) {
        if (!visited[u]) dfsUtil(u, adj, visited);
    }
}

void dfsGraph(vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            dfsUtil(i, adj, visited);
        }
    }
    cout << endl;
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> adj(V);
    
    // Adding edges to the graph
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(3);
    adj[3].push_back(4);
    
    cout << "BFS Traversal: ";
    bfsGraph(adj, V);
    
    cout << "DFS Traversal: ";
    dfsGraph(adj, V);
    
    return 0;
}