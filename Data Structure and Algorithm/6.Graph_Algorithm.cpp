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

const int V = 5; // Number of vertices

// ------------------------------
// 1. Adjacency Matrix
// ------------------------------
void printMatrix(vector<vector<int>>& matrix) {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}

// ------------------------------
// 2. Adjacency List
// ------------------------------
void printList(vector<vector<int>>& adj) {
    cout << "Adjacency List:\n";
    for (int i = 0; i < V; ++i) {
        cout << i << ": ";
        for (int neighbor : adj[i])
            cout << neighbor << " ";
        cout << "\n";
    }
}

// ------------------------------
// 3. BFS (Breadth-First Search)
// ------------------------------
void bfs(int start, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    cout << "BFS: ";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << "\n";
}

// ------------------------------
// 4. DFS (Depth-First Search)
// ------------------------------
void dfsUtil(int u, vector<bool>& visited, vector<vector<int>>& adj) {
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfsUtil(v, visited, adj);
        }
    }
}

void dfs(int start, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    cout << "DFS: ";
    dfsUtil(start, visited, adj);
    cout << "\n";
}

// ------------------------------
// MAIN Function
// ------------------------------
int main() {
    // Create sample graph: 0-1-3-4, and 0-2-3
    // Edges: (0,1), (0,2), (1,3), (2,3), (3,4)

    // Adjacency Matrix
    vector<vector<int>> matrix(V, vector<int>(V, 0));
    matrix[0][1] = matrix[1][0] = 1;
    matrix[0][2] = matrix[2][0] = 1;
    matrix[1][3] = matrix[3][1] = 1;
    matrix[2][3] = matrix[3][2] = 1;
    matrix[3][4] = matrix[4][3] = 1;

    // Adjacency List
    vector<vector<int>> adj(V);
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 3};
    adj[3] = {1, 2, 4};
    adj[4] = {3};

    // Print representations
    printMatrix(matrix);
    cout << "\n";
    printList(adj);
    cout << "\n";

    // Traversals
    bfs(0, adj);
    dfs(0, adj);

    return 0;
}