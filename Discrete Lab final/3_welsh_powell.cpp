#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<vector<int>> adj = {{0,1,1,0}, {1,0,1,1}, {1,1,0,1}, {0,1,1,0}};
    vector<pair<int, int>> degrees;
    for (int i=0; i<4; i++) {
        int deg = 0;
        for (int j=0; j<4; j++) deg += adj[i][j];
        degrees.push_back({i, deg});
    }
    sort(degrees.begin(), degrees.end(), [](auto &a, auto &b) { return a.second > b.second; });

    vector<int> color(4, -1);
    for (auto &p : degrees) {
        int v = p.first;
        if (color[v] != -1) continue;
        vector<bool> available(4, true);
        for (int u=0; u<4; u++)
            if (adj[v][u] && color[u] != -1) available[color[u]] = false;
        int cr = 0;
        while (!available[cr]) cr++;
        color[v] = cr;
    }
    cout << "Colors: ";
    for (int c : color) cout << c+1 << " ";
    return 0;
}