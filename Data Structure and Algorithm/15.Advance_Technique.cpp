// Advanced Algorithmic Techniques in C++

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
using namespace std;

//----------------------------------
// 1. Sliding Window
//----------------------------------
int maxSumSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) return -1;
    int max_sum = 0, window_sum = 0;
    for (int i = 0; i < k; ++i) window_sum += arr[i];
    max_sum = window_sum;
    for (int i = k; i < n; ++i) {
        window_sum += arr[i] - arr[i - k];
        max_sum = max(max_sum, window_sum);
    }
    return max_sum;
}

//----------------------------------
// 2. Two Pointers
//----------------------------------
bool hasTwoSum(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    int l = 0, r = arr.size() - 1;
    while (l < r) {
        int sum = arr[l] + arr[r];
        if (sum == target) return true;
        else if (sum < target) l++;
        else r--;
    }
    return false;
}

//----------------------------------
// 3. Mo's Algorithm
//----------------------------------
const int MAXN = 1e5 + 5;
int freq[MAXN], answer[MAXN];

struct Query {
    int l, r, idx;
};

int BLOCK;

bool compare(Query a, Query b) {
    if (a.l / BLOCK != b.l / BLOCK)
        return a.l / BLOCK < b.l / BLOCK;
    return a.r < b.r;
}

void add(int x, int& res) {
    freq[x]++;
    if (freq[x] == 1) res++;
}

void remove(int x, int& res) {
    freq[x]--;
    if (freq[x] == 0) res--;
}

void mosAlgorithm(vector<int>& arr, vector<Query>& queries) {
    BLOCK = sqrt(arr.size());
    sort(queries.begin(), queries.end(), compare);
    int currL = 0, currR = -1, res = 0;
    for (auto q : queries) {
        while (currL > q.l) add(arr[--currL], res);
        while (currR < q.r) add(arr[++currR], res);
        while (currL < q.l) remove(arr[currL++], res);
        while (currR > q.r) remove(arr[currR--], res);
        answer[q.idx] = res;
    }
}

//----------------------------------
// 4. Heavy-Light Decomposition (Skeleton Only)
//----------------------------------
const int N = 100005;
vector<int> tree[N];
int parent[N], depth[N], heavy[N], head[N], pos[N];
int current_pos;

int dfs(int v) {
    int size = 1, maxSubtree = 0;
    for (int u : tree[v]) {
        if (u != parent[v]) {
            parent[u] = v;
            depth[u] = depth[v] + 1;
            int subtree = dfs(u);
            size += subtree;
            if (subtree > maxSubtree) {
                maxSubtree = subtree;
                heavy[v] = u;
            }
        }
    }
    return size;
}

void decompose(int v, int h) {
    head[v] = h;
    pos[v] = current_pos++;
    if (heavy[v] != -1) decompose(heavy[v], h);
    for (int u : tree[v]) {
        if (u != parent[v] && u != heavy[v]) {
            decompose(u, u);
        }
    }
}

void initHLD(int root) {
    fill(heavy, heavy + N, -1);
    parent[root] = -1;
    depth[root] = 0;
    dfs(root);
    current_pos = 0;
    decompose(root, root);
}

//----------------------------------
// Main (Testing)
//----------------------------------
int main() {
    // Sliding Window
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << "Max sum of window size 3: " << maxSumSubarray(arr, 3) << endl;

    // Two Pointers
    cout << "Has Two Sum (target=9): " << (hasTwoSum(arr, 9) ? "Yes" : "No") << endl;

    // Mo's Algorithm (Example usage)
    vector<Query> queries = {{1, 3, 0}, {0, 4, 1}};
    mosAlgorithm(arr, queries);
    for (int i = 0; i < 2; i++) cout << "Answer to Query " << i << ": " << answer[i] << endl;

    return 0;
}
