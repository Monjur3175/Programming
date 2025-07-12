#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

//----------------------------------
// 1. Binary Tree
//----------------------------------
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

//----------------------------------
// 2. Binary Search Tree
//----------------------------------
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

//----------------------------------
// 3. AVL Tree
//----------------------------------
int height(TreeNode* node) {
    if (!node) return 0;
    return 1 + max(height(node->left), height(node->right));
}

int getBalance(TreeNode* node) {
    if (!node) return 0;
    return height(node->left) - height(node->right);
}

TreeNode* rotateRight(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    return x;
}

TreeNode* rotateLeft(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    return y;
}

TreeNode* insertAVL(TreeNode* node, int key) {
    if (!node) return new TreeNode(key);
    if (key < node->val) node->left = insertAVL(node->left, key);
    else if (key > node->val) node->right = insertAVL(node->right, key);
    else return node;

    int balance = getBalance(node);
    if (balance > 1 && key < node->left->val) return rotateRight(node);
    if (balance < -1 && key > node->right->val) return rotateLeft(node);
    if (balance > 1 && key > node->left->val) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && key < node->right->val) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

//----------------------------------
// 4. Trie
//----------------------------------
struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    TrieNode() { fill(begin(children), end(children), nullptr); isEnd = false; }
};

void insertTrie(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (!node->children[index]) node->children[index] = new TrieNode();
        node = node->children[index];
    }
    node->isEnd = true;
}

bool searchTrie(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (!node->children[index]) return false;
        node = node->children[index];
    }
    return node->isEnd;
}

//----------------------------------
// 5. Segment Tree
//----------------------------------
class SegmentTree {
    vector<int> tree;
    int n;

    void build(vector<int>& arr, int i, int l, int r) {
        if (l == r) tree[i] = arr[l];
        else {
            int m = (l + r) / 2;
            build(arr, 2*i, l, m);
            build(arr, 2*i+1, m+1, r);
            tree[i] = tree[2*i] + tree[2*i+1];
        }
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }
};

//----------------------------------
// 6. Fenwick Tree
//----------------------------------
class FenwickTree {
    vector<int> bit;
    int n;

public:
    FenwickTree(int size) : n(size) { bit.resize(n + 1); }

    void update(int i, int val) {
        while (i <= n) {
            bit[i] += val;
            i += i & -i;
        }
    }

    int query(int i) {
        int res = 0;
        while (i > 0) {
            res += bit[i];
            i -= i & -i;
        }
        return res;
    }
};

//----------------------------------
// 7. Min-Heap and Max-Heap
//----------------------------------
void demoHeaps() {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    maxHeap.push(10); minHeap.push(10);
    maxHeap.push(5);  minHeap.push(5);
    cout << "Max: " << maxHeap.top() << ", Min: " << minHeap.top() << endl;
}

//----------------------------------
// 8. Graphs
//----------------------------------
void graphMatrix() {
    int V = 4;
    int G[4][4] = {0};
    G[0][1] = 1;
    G[1][2] = 1;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j)
            cout << G[i][j] << " ";
        cout << endl;
    }
}

void graphList() {
    int V = 4;
    vector<vector<int>> adj(V);
    adj[0].push_back(1);
    adj[1].push_back(2);
    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        for (int j : adj[i]) cout << j << " ";
        cout << endl;
    }
}

//----------------------------------
// Main Driver
//----------------------------------
int main() {
    // Binary Tree
    TreeNode* bt = new TreeNode(10);
    bt->left = new TreeNode(5);
    bt->right = new TreeNode(20);
    inorder(bt);
    cout << endl;

    // BST
    TreeNode* bst = nullptr;
    bst = insertBST(bst, 50);
    insertBST(bst, 30);
    insertBST(bst, 70);
    inorder(bst);
    cout << endl;

    // AVL Tree
    TreeNode* avl = nullptr;
    avl = insertAVL(avl, 10);
    avl = insertAVL(avl, 20);
    avl = insertAVL(avl, 30);
    inorder(avl);
    cout << endl;

    // Trie
    TrieNode* trieRoot = new TrieNode();
    insertTrie(trieRoot, "apple");
    cout << searchTrie(trieRoot, "apple") << endl;

    // Segment Tree
    vector<int> arr = {1, 2, 3, 4, 5};
    SegmentTree st(arr);

    // Fenwick Tree
    FenwickTree ft(5);
    ft.update(1, 1);
    ft.update(2, 2);
    cout << ft.query(2) << endl;

    // Heap Demo
    demoHeaps();

    // Graph Representations
    graphMatrix();
    graphList();

    return 0;
}
