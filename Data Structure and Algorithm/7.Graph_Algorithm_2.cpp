#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <list>
#include <tuple>
#include <cstring>
using namespace std;

//----------------------------
// Shortest Path Algorithms
//----------------------------

// 1. Dijkstra's Algorithm (Non-negative weights)
void dijkstra(int src, vector<vector<pair<int, int>>> &graph)
{
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto &edge : graph[u])
        {
            int v = edge.first, w = edge.second;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Dijkstra distances from source " << src << ":\n";
    for (int i = 0; i < V; i++)
        cout << "Vertex " << i << ": " << (dist[i] == INT_MAX ? "INF" : to_string(dist[i])) << "\n";
}

// 2. Bellman-Ford Algorithm (Handles negative weights, detects negative cycles)
bool bellmanFord(int src, vector<tuple<int, int, int>> &edges, int V)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++)
    {
        for (auto &e : edges)
        {
            int u, v, w;
            tie(u, v, w) = e;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative-weight cycles
    for (auto &e : edges)
    {
        int u, v, w;
        tie(u, v, w) = e;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            cout << "Graph contains negative weight cycle\n";
            return false;
        }
    }

    cout << "Bellman-Ford distances from source " << src << ":\n";
    for (int i = 0; i < V; i++)
        cout << "Vertex " << i << ": " << (dist[i] == INT_MAX ? "INF" : to_string(dist[i])) << "\n";
    return true;
}

// 3. Floyd-Warshall Algorithm (All pairs shortest path)
void floydWarshall(vector<vector<int>> &graph)
{
    const int INF = INT_MAX / 2; // Prevent overflow
    int V = graph.size();
    vector<vector<int>> dist(V, vector<int>(V, INF));

    // Initialize
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else if (graph[i][j] != INF)
                dist[i][j] = graph[i][j];
        }
    }

    // Floyd-Warshall
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    cout << "Floyd-Warshall shortest paths:\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] >= INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

// 4. A* Algorithm (Heuristic-based) - For simplicity, this example uses Manhattan distance on grid

struct AStarNode
{
    int x, y, g, h;
    bool operator<(const AStarNode &other) const
    {
        return (g + h) > (other.g + other.h);
    }
};

int heuristic(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2); // Manhattan distance
}

bool isValid(int x, int y, int n, int m, vector<vector<int>> &grid)
{
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 0);
}

void AStar(int sx, int sy, int ex, int ey, vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    // Check if start or end is blocked
    if (grid[sx][sy] == 1 || grid[ex][ey] == 1)
    {
        cout << "A* could not find a path: start or end is an obstacle\n";
        return;
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    priority_queue<AStarNode> pq;
    pq.push({sx, sy, 0, heuristic(sx, sy, ex, ey)});

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    while (!pq.empty())
    {
        AStarNode cur = pq.top();
        pq.pop();

        if (cur.x == ex && cur.y == ey)
        {
            cout << "A* found path with cost: " << cur.g << "\n";
            return;
        }

        if (visited[cur.x][cur.y])
            continue;
        visited[cur.x][cur.y] = true;

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.x + dx[i], ny = cur.y + dy[i];
            if (isValid(nx, ny, n, m, grid) && !visited[nx][ny])
            {
                int ng = cur.g + 1;
                int nh = heuristic(nx, ny, ex, ey);
                pq.push({nx, ny, ng, nh});
            }
        }
    }
    cout << "A* could not find a path\n";
}

//----------------------------
// Minimum Spanning Tree (MST)
//----------------------------

// Prim's Algorithm
void primMST(vector<vector<pair<int, int>>> &graph)
{
    int V = graph.size();
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    vector<int> parent(V, -1);
    key[0] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = -1;
        int minKey = INT_MAX;
        for (int v = 0; v < V; v++)
        {
            if (!inMST[v] && key[v] < minKey)
            {
                minKey = key[v];
                u = v;
            }
        }
        inMST[u] = true;

        for (auto &edge : graph[u])
        {
            int v = edge.first, w = edge.second;
            if (!inMST[v] && w < key[v])
            {
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    cout << "Prim's MST edges:\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "\n";
}

// Union-Find (Disjoint Set) for Kruskal & Cycle detection
struct UnionFind
{
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 0)
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y)
    {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry)
            return false;
        if (rank[rx] < rank[ry])
            parent[rx] = ry;
        else if (rank[ry] < rank[rx])
            parent[ry] = rx;
        else
        {
            parent[ry] = rx;
            rank[rx]++;
        }
        return true;
    }
};

// Kruskal's Algorithm
void kruskalMST(int V, vector<tuple<int, int, int>> &edges)
{
    sort(edges.begin(), edges.end(), [](auto &a, auto &b)
         { return get<2>(a) < get<2>(b); });

    UnionFind uf(V);
    cout << "Kruskal's MST edges:\n";
    for (auto &e : edges)
    {
        int u, v, w;
        tie(u, v, w) = e;
        if (uf.unite(u, v))
            cout << u << " - " << v << "\n";
    }
}

//----------------------------
// Cycle Detection
//----------------------------

// Cycle detection using Union-Find in undirected graph
bool hasCycle(int V, vector<pair<int, int>> &edges)
{
    UnionFind uf(V);
    for (auto &e : edges)
    {
        if (!uf.unite(e.first, e.second))
            return true;
    }
    return false;
}

//----------------------------
// Topological Sort (Kahn's Algorithm)
//----------------------------

vector<int> topologicalSort(int V, vector<vector<int>> &adj)
{
    vector<int> indegree(V, 0), order;
    for (int u = 0; u < V; u++)
        for (int v : adj[u])
            indegree[v]++;

    queue<int> q;
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : adj[u])
        {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }
    if (order.size() != V)
        return {}; // Cycle detected
    return order;
}

//----------------------------
// Strongly Connected Components (Kosaraju)
//----------------------------

void dfsForSCC(int u, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &order)
{
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v])
            dfsForSCC(v, adj, visited, order);
    order.push_back(u);
}

void dfsOnTranspose(int u, vector<vector<int>> &transpose, vector<bool> &visited)
{
    visited[u] = true;
    cout << u << " ";
    for (int v : transpose[u])
        if (!visited[v])
            dfsOnTranspose(v, transpose, visited);
}

void kosarajuSCC(vector<vector<int>> &adj)
{
    int V = adj.size();
    vector<bool> visited(V, false);
    vector<int> order;

    // 1. DFS and store finish order
    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfsForSCC(i, adj, visited, order);

    // 2. Transpose graph
    vector<vector<int>> transpose(V);
    for (int u = 0; u < V; u++)
        for (int v : adj[u])
            transpose[v].push_back(u);

    // 3. DFS on transpose graph in reverse finish time order
    fill(visited.begin(), visited.end(), false);
    cout << "Strongly Connected Components:\n";
    for (int i = V - 1; i >= 0; i--)
    {
        int node = order[i];
        if (!visited[node])
        {
            dfsOnTranspose(node, transpose, visited);
            cout << "\n";
        }
    }
}

//----------------------------
// Strongly Connected Components (Tarjan's Algorithm)
//----------------------------

class TarjanSCC
{
    vector<vector<int>> &graph;
    vector<int> disc, low;
    vector<bool> stackMember;
    stack<int> st;
    int time;

public:
    TarjanSCC(vector<vector<int>> &g) : graph(g)
    {
        int V = g.size();
        disc.assign(V, -1);
        low.assign(V, -1);
        stackMember.assign(V, false);
        time = 0;
    }
    void SCCUtil(int u)
    {
        disc[u] = low[u] = time++;
        st.push(u);
        stackMember[u] = true;

        for (int v : graph[u])
        {
            if (disc[v] == -1)
            {
                SCCUtil(v);
                low[u] = min(low[u], low[v]);
            }
            else if (stackMember[v])
            {
                low[u] = min(low[u], disc[v]);
            }
        }

        if (low[u] == disc[u])
        {
            cout << "SCC: ";
            while (true)
            {
                int w = st.top();
                st.pop();
                stackMember[w] = false;
                cout << w << " ";
                if (w == u)
                    break;
            }
            cout << "\n";
        }
    }
    void findSCC()
    {
        int V = graph.size();
        for (int i = 0; i < V; i++)
        {
            if (disc[i] == -1)
                SCCUtil(i);
        }
    }
};

//----------------------------
// Network Flow Algorithms
//----------------------------

// Ford-Fulkerson using DFS for augmenting paths
bool fordFulkersonDFS(int u, int t, vector<vector<int>> &residualGraph, vector<bool> &visited, int flow)
{
    if (u == t)
        return flow;
    visited[u] = true;
    for (int v = 0; v < residualGraph.size(); v++)
    {
        if (!visited[v] && residualGraph[u][v] > 0)
        {
            int curr_flow = min(flow, residualGraph[u][v]);
            int temp_flow = fordFulkersonDFS(v, t, residualGraph, visited, curr_flow);
            if (temp_flow > 0)
            {
                residualGraph[u][v] -= temp_flow;
                residualGraph[v][u] += temp_flow;
                return temp_flow;
            }
        }
    }
    return 0;
}

int fordFulkerson(int s, int t, vector<vector<int>> &graph)
{
    int max_flow = 0;
    int V = graph.size();
    vector<vector<int>> residualGraph = graph;
    while (true)
    {
        vector<bool> visited(V, false);
        int flow = fordFulkersonDFS(s, t, residualGraph, visited, INT_MAX);
        if (flow == 0)
            break;
        max_flow += flow;
    }
    return max_flow;
}

// Edmonds-Karp implementation (using BFS for shortest augmenting path)
int bfsEK(int s, int t, vector<vector<int>> &residualGraph, vector<int> &parent)
{
    int V = residualGraph.size();
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && residualGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[t];
}

int edmondsKarp(int s, int t, vector<vector<int>> &graph)
{
    int max_flow = 0;
    int V = graph.size();
    vector<vector<int>> residualGraph = graph;
    vector<int> parent(V);

    while (bfsEK(s, t, residualGraph, parent))
    {
        int path_flow = INT_MAX;
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            path_flow = min(path_flow, residualGraph[u][v]);
        }
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            residualGraph[u][v] -= path_flow;
            residualGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

//----------------------------
// Demo main
//----------------------------

int main()
{
    // Dijkstra demo
    vector<vector<pair<int, int>>> graph = {
        {{1, 4}, {2, 1}},
        {{3, 1}},
        {{1, 2}, {3, 5}},
        {}};
    dijkstra(0, graph);

    // Bellman-Ford demo
    vector<tuple<int, int, int>> edges = {
        {0, 1, 4}, {0, 2, 1}, {2, 1, 2}, {1, 3, 1}, {2, 3, 5}};
    bellmanFord(0, edges, 4);

    // Floyd-Warshall demo
    const int INF = INT_MAX / 2;
    vector<vector<int>> fwGraph = {
        {0, 3, INF, 5},
        {2, 0, INF, 4},
        {INF, 1, 0, INF},
        {INF, INF, 2, 0}};
    floydWarshall(fwGraph);

    // A* demo grid: 0 = free cell, 1 = obstacle
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};
    AStar(0, 0, 4, 3, grid);

    // Prim MST demo
    vector<vector<pair<int, int>>> primGraph = {
        {{1, 2}, {3, 6}},
        {{0, 2}, {2, 3}, {3, 8}},
        {{1, 3}, {3, 0}},
        {{0, 6}, {1, 8}, {2, 0}}};
    primMST(primGraph);

    // Kruskal MST demo
    vector<tuple<int, int, int>> kruskalEdges = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {2, 3, 0}};
    kruskalMST(4, kruskalEdges);

    // Cycle detection demo
    vector<pair<int, int>> cycleEdges = {{0, 1}, {1, 2}, {2, 3}, {3, 1}};
    cout << "Cycle detected? " << (hasCycle(4, cycleEdges) ? "Yes\n" : "No\n");

    // Topological Sort demo
    vector<vector<int>> dag = {
        {1, 2}, {2, 3}, {}, {}};
    auto topoOrder = topologicalSort(4, dag);
    if (topoOrder.empty())
        cout << "Cycle detected in graph - no topo sort\n";
    else
    {
        cout << "Topological Order: ";
        for (int v : topoOrder)
            cout << v << " ";
        cout << "\n";
    }

    // Updated SCC graph for clearer components
    vector<vector<int>> sccGraph = {
        {1},           // 0 -> 1
        {2},           // 1 -> 2
        {0, 3},        // 2 -> 0 and 2 -> 3
        {4},           // 3 -> 4
        {3}            // 4 -> 3
    };

    kosarajuSCC(sccGraph);

    // Tarjan SCC demo
    TarjanSCC tarjan(sccGraph);
    cout << "Tarjan's SCC:\n";
    tarjan.findSCC();

    // Ford-Fulkerson demo
    vector<vector<int>> flowGraph = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}};
    cout << "Max Flow (Ford-Fulkerson): " << fordFulkerson(0, 5, flowGraph) << "\n";

    // Edmonds-Karp demo
    cout << "Max Flow (Edmonds-Karp): " << edmondsKarp(0, 5, flowGraph) << "\n";

    return 0;
}