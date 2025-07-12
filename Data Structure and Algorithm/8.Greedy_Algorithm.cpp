#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

//--------------------------
// 1. Activity Selection Problem
// Select maximum number of activities that don't overlap
struct Activity {
    int start, finish;
};
bool activityCompare(Activity a, Activity b) {
    return a.finish < b.finish;
}
int activitySelection(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), activityCompare);
    int count = 1; // select first activity
    int lastFinish = activities[0].finish;

    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= lastFinish) {
            count++;
            lastFinish = activities[i].finish;
        }
    }
    return count;
}

//--------------------------
// 2. Fractional Knapsack Problem
struct Item {
    int value, weight;
};
bool fractionalCompare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}
double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), fractionalCompare);
    double totalValue = 0.0;
    int currWeight = 0;

    for (auto& item : items) {
        if (currWeight + item.weight <= W) {
            currWeight += item.weight;
            totalValue += item.value;
        } else {
            int remain = W - currWeight;
            totalValue += item.value * ((double)remain / item.weight);
            break;
        }
    }
    return totalValue;
}

//--------------------------
// 3. Huffman Coding
struct HuffmanNode {
    char ch;
    int freq;
    HuffmanNode *left, *right;
    HuffmanNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
    HuffmanNode(HuffmanNode* l, HuffmanNode* r) : ch('\0'), freq(l->freq + r->freq), left(l), right(r) {}
};
struct CompareNode {
    bool operator()(HuffmanNode* l, HuffmanNode* r) {
        return l->freq > r->freq;
    }
};
void printHuffmanCodes(HuffmanNode* root, string code) {
    if (!root) return;
    if (!root->left && !root->right) {
        cout << root->ch << ": " << code << "\n";
    }
    printHuffmanCodes(root->left, code + "0");
    printHuffmanCodes(root->right, code + "1");
}
void huffmanCoding(const vector<char>& chars, const vector<int>& freqs) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNode> pq;
    for (int i = 0; i < chars.size(); i++) {
        pq.push(new HuffmanNode(chars[i], freqs[i]));
    }

    while (pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();
        pq.push(new HuffmanNode(left, right));
    }
    HuffmanNode* root = pq.top();
    printHuffmanCodes(root, "");
    // Memory cleanup omitted for brevity
}

//--------------------------
// 4. Job Sequencing Problem
struct Job {
    int id, deadline, profit;
};
bool jobCompare(Job a, Job b) {
    return a.profit > b.profit;
}
int jobSequencing(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), jobCompare);
    int n = jobs.size();
    vector<int> result(n, -1);
    vector<bool> slot(n, false);

    int countJobs = 0, totalProfit = 0;
    for (auto& job : jobs) {
        for (int j = min(n, job.deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                result[j] = job.id;
                totalProfit += job.profit;
                countJobs++;
                break;
            }
        }
    }
    return totalProfit;
}

//--------------------------
// Demo runner
//--------------------------
int main() {
    // Activity Selection
    vector<Activity> activities = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    cout << "Max activities selected: " << activitySelection(activities) << "\n";

    // Fractional Knapsack
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    int W = 50;
    cout << "Max value in Fractional Knapsack: " << fractionalKnapsack(W, items) << "\n";

    // Huffman Coding
    vector<char> chars = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> freqs = {5, 9, 12, 13, 16, 45};
    cout << "Huffman Codes:\n";
    huffmanCoding(chars, freqs);

    // Job Sequencing
    vector<Job> jobs = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
    cout << "Max profit from job sequencing: " << jobSequencing(jobs) << "\n";

    return 0;
}
