// Hash-Based Structures in C++

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//----------------------------------
// 1. Hash Table using Separate Chaining
//----------------------------------
class HashTableChaining {
private:
    int BUCKET;
    vector<list<int>> table;

    int hashFunction(int key) {
        return key % BUCKET;
    }

public:
    HashTableChaining(int b) : BUCKET(b), table(b) {}

    void insertItem(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void deleteItem(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    void displayHash() {
        for (int i = 0; i < BUCKET; i++) {
            cout << i;
            for (int x : table[i])
                cout << " --> " << x;
            cout << endl;
        }
    }
};

//----------------------------------
// 2. Hash Table using Open Addressing (Linear Probing)
//----------------------------------
class HashTableOpenAddressing {
private:
    vector<int> table;
    int size;
    const int EMPTY = -1;

    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTableOpenAddressing(int s) : size(s), table(s, EMPTY) {}

    void insert(int key) {
        int index = hashFunction(key);
        int i = 0;
        while (table[(index + i) % size] != EMPTY && i < size) i++;
        if (i == size) cout << "Hash table is full\n";
        else table[(index + i) % size] = key;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << i << ": " << (table[i] == EMPTY ? "EMPTY" : to_string(table[i])) << endl;
    }
};

//----------------------------------
// 3. C++ STL: unordered_map & unordered_set
//----------------------------------
void stlHashDemo() {
    unordered_map<string, int> umap;
    umap["apple"] = 3;
    umap["banana"] = 5;

    cout << "unordered_map demo:\n";
    for (auto& kv : umap)
        cout << kv.first << " => " << kv.second << endl;

    unordered_set<int> uset = {1, 2, 3, 4};
    uset.insert(5);

    cout << "\nunordered_set demo:\n";
    for (int val : uset)
        cout << val << " ";
    cout << endl;
}

//----------------------------------
// Main for Testing
//----------------------------------
int main() {
    cout << "=== Separate Chaining ===\n";
    HashTableChaining htc(7);
    htc.insertItem(10);
    htc.insertItem(20);
    htc.insertItem(15);
    htc.insertItem(7);
    htc.displayHash();

    cout << "\n=== Open Addressing ===\n";
    HashTableOpenAddressing hto(7);
    hto.insert(10);
    hto.insert(20);
    hto.insert(15);
    hto.insert(7);
    hto.display();

    cout << "\n=== STL Hash Demo ===\n";
    stlHashDemo();

    return 0;
}
