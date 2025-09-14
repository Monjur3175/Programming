#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

//------------------------------
// 1. Binary Tree
//------------------------------
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

//------------------------------
// 2. Binary Search Tree (BST)
//------------------------------
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insertBST(root->left, val);
    else if (val > root->val)
        root->right = insertBST(root->right, val);
    return root;
}

TreeNode* searchBST(TreeNode* root, int val) {
    if (!root || root->val == val) return root;
    if (val < root->val) return searchBST(root->left, val);
    return searchBST(root->right, val);
}

//------------------------------
// 3. AVL Tree (Self-Balancing BST)
//------------------------------
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

    if (key < node->val)
        node->left = insertAVL(node->left, key);
    else if (key > node->val)
        node->right = insertAVL(node->right, key);
    else
        return node;

    int balance = getBalance(node);

    // Left Left
    if (balance > 1 && key < node->left->val)
        return rotateRight(node);

    // Right Right
    if (balance < -1 && key > node->right->val)
        return rotateLeft(node);

    // Left Right
    if (balance > 1 && key > node->left->val) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left
    if (balance < -1 && key < node->right->val) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

//------------------------------
// 4. Trie (Prefix Tree)
//------------------------------
struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    TrieNode() {
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
        isEnd = false;
    }
};

void insertTrie(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (char c : word) {
        int idx = c - 'a';
        if (!node->children[idx])
            node->children[idx] = new TrieNode();
        node = node->children[idx];
    }
    node->isEnd = true;
}

bool searchTrie(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (char c : word) {
        int idx = c - 'a';
        if (!node->children[idx]) return false;
        node = node->children[idx];
    }
    return node->isEnd;
}

//------------------------------
// 5. Segment Tree (Range Sum Query)
//------------------------------
class SegmentTree {
    vector<int> tree;
    int n;

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) +
               query(2 * node + 1, mid + 1, end, l, r);
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n, 0);
        if (n > 0) build(arr, 1, 0, n - 1);
    }

    int rangeSum(int l, int r) {
        if (n == 0) return 0;
        return query(1, 0, n - 1, l, r);
    }
};

//------------------------------
// 6. Fenwick Tree (Binary Indexed Tree)
//------------------------------
class FenwickTree {
    vector<int> bit;
    int n;

public:
    FenwickTree(int size) : n(size) {
        bit.resize(n + 1, 0);
    }

    void update(int index, int delta) {
        while (index <= n) {
            bit[index] += delta;
            index += index & (-index);
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += bit[index];
            index -= index & (-index);
        }
        return sum;
    }

    int rangeSum(int l, int r) {
        return query(r) - query(l - 1);
    }
};

//------------------------------
// 7. Min-Max Heaps
//------------------------------
void demoHeaps() {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    maxHeap.push(10); maxHeap.push(5); maxHeap.push(20);
    minHeap.push(10); minHeap.push(5); minHeap.push(20);

    cout << "Max Heap Top: " << maxHeap.top() << endl;
    cout << "Min Heap Top: " << minHeap.top() << endl;
}

//------------------------------
// 8. Red-Black Tree (Simplified Implementation)
//------------------------------
enum Color { RED, BLACK };

struct RBNode {
    int key;
    Color color;
    RBNode* left;
    RBNode* right;
    RBNode* parent;
    RBNode(int k) : key(k), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    RBNode* root;
    RBNode* NIL; // Sentinel node (for leafs)

    void leftRotate(RBNode* x) {
        RBNode* y = x->right;
        x->right = y->left;
        if (y->left != NIL) y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void rightRotate(RBNode* y) {
        RBNode* x = y->left;
        y->left = x->right;
        if (x->right != NIL) x->right->parent = y;
        x->parent = y->parent;
        if (y->parent == nullptr) root = x;
        else if (y == y->parent->right) y->parent->right = x;
        else y->parent->left = x;
        x->right = y;
        y->parent = x;
    }

    void fixInsert(RBNode* k) {
        while (k->parent->color == RED) {
            if (k->parent == k->parent->parent->right) {
                RBNode* u = k->parent->parent->left;
                if (u->color == RED) {
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    leftRotate(k->parent->parent);
                }
            } else {
                RBNode* u = k->parent->parent->right;
                if (u->color == RED) {
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->right) {
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    rightRotate(k->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    void transplant(RBNode* u, RBNode* v) {
        if (u->parent == nullptr) root = v;
        else if (u == u->parent->left) u->parent->left = v;
        else u->parent->right = v;
        v->parent = u->parent;
    }

    void deleteFix(RBNode* x) {
        while (x != root && x->color == BLACK) {
            if (x == x->parent->left) {
                RBNode* w = x->parent->right;
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    leftRotate(x->parent);
                    w = x->parent->right;
                }
                if (w->left->color == BLACK && w->right->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->right->color == BLACK) {
                        w->left->color = BLACK;
                        w->color = RED;
                        rightRotate(w);
                        w = x->parent->right;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->right->color = BLACK;
                    leftRotate(x->parent);
                    x = root;
                }
            } else {
                RBNode* w = x->parent->left;
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rightRotate(x->parent);
                    w = x->parent->left;
                }
                if (w->right->color == BLACK && w->left->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->left->color == BLACK) {
                        w->right->color = BLACK;
                        w->color = RED;
                        leftRotate(w);
                        w = x->parent->left;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

    RBNode* searchNode(RBNode* node, int key) {
        if (node == NIL || key == node->key) return node;
        if (key < node->key) return searchNode(node->left, key);
        return searchNode(node->right, key);
    }

public:
    RedBlackTree() {
        NIL = new RBNode(0);
        NIL->color = BLACK;
        NIL->left = NIL->right = NIL->parent = NIL;
        root = NIL;
    }

    void insert(int key) {
        RBNode* newNode = new RBNode(key);
        newNode->left = NIL;
        newNode->right = NIL;

        RBNode* y = nullptr;
        RBNode* x = root;

        while (x != NIL) {
            y = x;
            if (newNode->key < x->key) x = x->left;
            else x = x->right;
        }

        newNode->parent = y;
        if (y == nullptr) root = newNode;
        else if (newNode->key < y->key) y->left = newNode;
        else y->right = newNode;

        newNode->color = RED;
        fixInsert(newNode);
    }

    void deleteNode(int key) {
        RBNode* z = searchNode(root, key);
        if (z == NIL) return;

        RBNode* y = z;
        Color yOriginalColor = y->color;
        RBNode* x;

        if (z->left == NIL) {
            x = z->right;
            transplant(z, z->right);
        } else if (z->right == NIL) {
            x = z->left;
            transplant(z, z->left);
        } else {
            y = minimum(z->right);
            yOriginalColor = y->color;
            x = y->right;
            if (y->parent == z) x->parent = y;
            else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        if (yOriginalColor == BLACK) deleteFix(x);
    }

    RBNode* minimum(RBNode* node) {
        while (node->left != NIL) node = node->left;
        return node;
    }

    void inorder() {
        inorderHelper(root);
        cout << endl;
    }

    void inorderHelper(RBNode* node) {
        if (node != NIL) {
            inorderHelper(node->left);
            cout << node->key << " ";
            inorderHelper(node->right);
        }
    }

    bool search(int key) {
        return searchNode(root, key) != NIL;
    }
};

//------------------------------
// 9. B-Tree (Simplified - Order 3)
//------------------------------
#define M 3 // Minimum degree (order = 2*M - 1 = 5 keys max per node)

struct BTreeNode {
    int keys[M - 1];   // Maximum M-1 keys
    BTreeNode* children[M]; // Maximum M children
    int numKeys;       // Number of keys currently stored
    bool leaf;

    BTreeNode(bool isLeaf) : leaf(isLeaf), numKeys(0) {
        for (int i = 0; i < M; ++i) children[i] = nullptr;
        for (int i = 0; i < M - 1; ++i) keys[i] = 0;
    }
};

class BTree {
private:
    BTreeNode* root;
    int t; // Minimum degree (t=2 means order=3)

    void splitChild(BTreeNode* x, int i) {
        BTreeNode* y = x->children[i];
        BTreeNode* z = new BTreeNode(y->leaf);
        z->numKeys = t - 1;

        // Copy last t-1 keys of y to z
        for (int j = 0; j < t - 1; ++j)
            z->keys[j] = y->keys[j + t];

        if (!y->leaf) {
            for (int j = 0; j < t; ++j)
                z->children[j] = y->children[j + t];
        }

        y->numKeys = t - 1;

        // Move one key from y to x
        for (int j = x->numKeys; j >= i + 1; --j)
            x->children[j + 1] = x->children[j];
        x->children[i + 1] = z;

        for (int j = x->numKeys - 1; j >= i; --j)
            x->keys[j + 1] = x->keys[j];
        x->keys[i] = y->keys[t - 1];
        x->numKeys++;
    }

    void insertNonFull(BTreeNode* x, int k) {
        int i = x->numKeys - 1;
        if (x->leaf) {
            while (i >= 0 && k < x->keys[i]) {
                x->keys[i + 1] = x->keys[i];
                i--;
            }
            x->keys[i + 1] = k;
            x->numKeys++;
        } else {
            while (i >= 0 && k < x->keys[i]) i--;
            i++;
            if (x->children[i]->numKeys == 2 * t - 1) {
                splitChild(x, i);
                if (k > x->keys[i]) i++;
            }
            insertNonFull(x->children[i], k);
        }
    }

    void traverse(BTreeNode* x) {
        for (int i = 0; i < x->numKeys; ++i) {
            if (!x->leaf) traverse(x->children[i]);
            cout << x->keys[i] << " ";
        }
        if (!x->leaf) traverse(x->children[x->numKeys]);
    }

    BTreeNode* search(BTreeNode* x, int k) {
        int i = 0;
        while (i < x->numKeys && k > x->keys[i]) i++;
        if (i < x->numKeys && k == x->keys[i]) return x;
        if (x->leaf) return nullptr;
        return search(x->children[i], k);
    }

public:
    BTree() : t(M / 2), root(nullptr) {}

    void insert(int k) {
        if (!root) {
            root = new BTreeNode(true);
            root->keys[0] = k;
            root->numKeys = 1;
        } else {
            if (root->numKeys == 2 * t - 1) {
                BTreeNode* s = new BTreeNode(false);
                s->children[0] = root;
                splitChild(s, 0);
                root = s;
                insertNonFull(root, k);
            } else {
                insertNonFull(root, k);
            }
        }
    }

    void traverse() {
        if (root) traverse(root);
        cout << endl;
    }

    bool search(int k) {
        return search(root, k) != nullptr;
    }
};

//------------------------------
// 10. B+ Tree (Simplified - All data in leaves, internal nodes are indexes)
//------------------------------
struct BPlusNode {
    vector<int> keys;
    vector<BPlusNode*> children;
    bool isLeaf;
    BPlusNode* next; // For sequential access

    BPlusNode(bool leaf) : isLeaf(leaf), next(nullptr) {
        keys.reserve(M - 1);
        children.reserve(M);
    }
};

class BPlusTree {
private:
    int t; // Minimum degree
    BPlusNode* root;

    void insertIntoLeaf(BPlusNode* leaf, int key) {
        int i = 0;
        while (i < leaf->keys.size() && leaf->keys[i] < key) i++;
        leaf->keys.insert(leaf->keys.begin() + i, key);
    }

    BPlusNode* splitLeaf(BPlusNode* leaf) {
        int mid = leaf->keys.size() / 2;
        BPlusNode* newLeaf = new BPlusNode(true);
        newLeaf->next = leaf->next;
        leaf->next = newLeaf;

        // Split keys
        for (int i = mid; i < leaf->keys.size(); ++i) {
            newLeaf->keys.push_back(leaf->keys[i]);
        }
        leaf->keys.resize(mid);

        return newLeaf;
    }

    void insertInternal(BPlusNode* node, int key, BPlusNode* child) {
        int i = 0;
        while (i < node->keys.size() && node->keys[i] < key) i++;
        node->keys.insert(node->keys.begin() + i, key);
        node->children.insert(node->children.begin() + i + 1, child);
    }

    pair<int, BPlusNode*> splitInternal(BPlusNode* node) {
        int mid = node->keys.size() / 2;
        int median = node->keys[mid];

        BPlusNode* newRight = new BPlusNode(false);
        for (int i = mid + 1; i < node->keys.size(); ++i) {
            newRight->keys.push_back(node->keys[i]);
            newRight->children.push_back(node->children[i]);
        }
        newRight->children.push_back(node->children.back());
        node->keys.resize(mid);
        node->children.resize(mid + 1);

        return {median, newRight};
    }

    void insertRecursive(BPlusNode*& node, int key) {
        if (node->isLeaf) {
            insertIntoLeaf(node, key);
            if (node->keys.size() >= M) {
                BPlusNode* newLeaf = splitLeaf(node);
                if (node == root) {
                    root = new BPlusNode(false);
                    root->keys.push_back(newLeaf->keys[0]);
                    root->children.push_back(node);
                    root->children.push_back(newLeaf);
                } else {
                    // Propagate up
                    insertInternal(root, newLeaf->keys[0], newLeaf);
                }
            }
        } else {
            int i = 0;
            while (i < node->keys.size() && key >= node->keys[i]) i++;
            insertRecursive(node->children[i], key);
            if (node->children[i]->keys.size() >= M) {
                auto p = splitInternal(node->children[i]);
                insertInternal(node, p.first, p.second);
            }
        }
    }

    void traverseLeaves(BPlusNode* node) {
        while (node) {
            for (int key : node->keys) cout << key << " ";
            node = node->next;
        }
        cout << endl;
    }

public:
    BPlusTree() : t(M / 2), root(nullptr) {}

    void insert(int key) {
        if (!root) {
            root = new BPlusNode(true);
            root->keys.push_back(key);
        } else {
            insertRecursive(root, key);
        }
    }

    void traverse() {
        if (root) traverseLeaves(root);
    }

    bool search(int key) {
        BPlusNode* node = root;
        while (node) {
            if (node->isLeaf) {
                for (int k : node->keys)
                    if (k == key) return true;
                return false;
            }
            int i = 0;
            while (i < node->keys.size() && key >= node->keys[i]) i++;
            node = node->children[i];
        }
        return false;
    }
};

//------------------------------
// 11. Graphs (Already defined)
//------------------------------
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

//------------------------------
// 12. Heaps (Already defined)
//------------------------------
void demoHeaps() {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    maxHeap.push(10); maxHeap.push(5); maxHeap.push(20);
    minHeap.push(10); minHeap.push(5); minHeap.push(20);

    cout << "Max Heap Top: " << maxHeap.top() << endl;
    cout << "Min Heap Top: " << minHeap.top() << endl;
}

//------------------------------
// MAIN DRIVER
//------------------------------
int main() {
    cout << "========== COMPLETE TREE DATA STRUCTURES ==========\n\n";

    // 1. Binary Tree
    cout << "1. Binary Tree:\n";
    TreeNode* bt = new TreeNode(1);
    bt->left = new TreeNode(2);
    bt->right = new TreeNode(3);
    bt->left->left = new TreeNode(4);
    bt->left->right = new TreeNode(5);
    cout << "Inorder: "; inorder(bt); cout << endl;

    // 2. BST
    cout << "\n2. BST:\n";
    TreeNode* bst = nullptr;
    bst = insertBST(bst, 50);
    insertBST(bst, 30); insertBST(bst, 70);
    insertBST(bst, 20); insertBST(bst, 40);
    cout << "Inorder: "; inorder(bst); cout << endl;

    // 3. AVL Tree
    cout << "\n3. AVL Tree:\n";
    TreeNode* avl = nullptr;
    avl = insertAVL(avl, 10);
    avl = insertAVL(avl, 20);
    avl = insertAVL(avl, 30);
    avl = insertAVL(avl, 40);
    avl = insertAVL(avl, 50);
    cout << "Inorder: "; inorder(avl); cout << endl;

    // 4. Trie
    cout << "\n4. Trie:\n";
    TrieNode* trieRoot = new TrieNode();
    insertTrie(trieRoot, "apple");
    insertTrie(trieRoot, "app");
    cout << "Search 'apple': " << (searchTrie(trieRoot, "apple") ? "Yes" : "No") << endl;

    // 5. Segment Tree
    cout << "\n5. Segment Tree:\n";
    vector<int> arr = {1, 3, 5, 7, 9};
    SegmentTree st(arr);
    cout << "Sum [1,3]: " << st.rangeSum(1, 3) << endl;

    // 6. Fenwick Tree
    cout << "\n6. Fenwick Tree:\n";
    FenwickTree ft(5);
    for (int i = 0; i < 5; ++i) ft.update(i + 1, arr[i]);
    cout << "Sum [1,4]: " << ft.rangeSum(1, 4) << endl;

    // 7. Heaps
    cout << "\n7. Heaps:\n";
    demoHeaps();

    // 8. Red-Black Tree
    cout << "\n8. Red-Black Tree:\n";
    RedBlackTree rbt;
    rbt.insert(10); rbt.insert(20); rbt.insert(30);
    rbt.insert(15); rbt.insert(25); rbt.insert(5);
    cout << "Inorder: "; rbt.inorder();
    cout << "Search 15: " << (rbt.search(15) ? "Found" : "Not Found") << endl;

    // 9. B-Tree
    cout << "\n9. B-Tree (Order 3):\n";
    BTree btree;
    btree.insert(10);
    btree.insert(20);
    btree.insert(5);
    btree.insert(6);
    btree.insert(12);
    btree.insert(30);
    btree.insert(7);
    btree.insert(17);
    cout << "Keys: ";
    btree.traverse();

    // 10. B+ Tree
    cout << "\n10. B+ Tree (Order 3):\n";
    BPlusTree bpt;
    bpt.insert(10);
    bpt.insert(20);
    bpt.insert(5);
    bpt.insert(6);
    bpt.insert(12);
    bpt.insert(30);
    bpt.insert(7);
    bpt.insert(17);
    cout << "All keys (leaf scan): ";
    bpt.traverse();

    // 11. Graphs
    cout << "\n11. Graph Representations:\n";
    graphMatrix();
    graphList();

    cout << "\n===================================================\n";
    return 0;
}