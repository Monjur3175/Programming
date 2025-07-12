#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

//----------------------------------
// LINEAR DATA STRUCTURES
//----------------------------------

// 1. Static Array (1D, 2D)
void staticArrayDemo() {
    int arr1D[5] = {1, 2, 3, 4, 5};
    int arr2D[2][3] = {{1, 2, 3}, {4, 5, 6}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) cout << arr2D[i][j] << " ";
        cout << endl;
    }
}

// 2. Dynamic Array (vector)
void dynamicArrayDemo() {
    vector<int> vec = {1, 2, 3};
    vec.push_back(4);
    for (int v : vec) cout << v << " ";
    cout << endl;
}

// 3. Singly Linked List
struct SLLNode {
    int data;
    SLLNode* next;
    SLLNode(int val) : data(val), next(nullptr) {}
};

void printSLL(SLLNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// 4. Doubly Linked List
struct DLLNode {
    int data;
    DLLNode* prev, *next;
    DLLNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

void printDLL(DLLNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// 5. Circular Linked List
struct CLLNode {
    int data;
    CLLNode* next;
    CLLNode(int val) : data(val), next(nullptr) {}
};

void printCLL(CLLNode* head) {
    if (!head) return;
    CLLNode* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// 6. Stack (Array-based)
class StackArray {
    vector<int> arr;
public:
    void push(int x) { arr.push_back(x); }
    void pop() { if (!arr.empty()) arr.pop_back(); }
    int top() { return arr.back(); }
    bool empty() { return arr.empty(); }
};

// 7. Stack (Linked List-based)
struct StackNode {
    int data;
    StackNode* next;
    StackNode(int val) : data(val), next(nullptr) {}
};

class StackLL {
    StackNode* topNode;
public:
    StackLL() : topNode(nullptr) {}
    void push(int x) {
        StackNode* newNode = new StackNode(x);
        newNode->next = topNode;
        topNode = newNode;
    }
    void pop() {
        if (topNode) {
            StackNode* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }
    int top() { return topNode->data; }
    bool empty() { return topNode == nullptr; }
};

// 8. Queue (Simple)
class QueueArray {
    vector<int> arr;
public:
    void enqueue(int x) { arr.push_back(x); }
    void dequeue() { if (!arr.empty()) arr.erase(arr.begin()); }
    int front() { return arr.front(); }
    bool empty() { return arr.empty(); }
};

// 9. Circular Queue
class CircularQueue {
    vector<int> cq;
    int size, front, rear, count;
public:
    CircularQueue(int k) : cq(k), size(k), front(0), rear(0), count(0) {}
    bool enqueue(int val) {
        if (count == size) return false;
        cq[rear] = val;
        rear = (rear + 1) % size;
        count++;
        return true;
    }
    bool dequeue() {
        if (count == 0) return false;
        front = (front + 1) % size;
        count--;
        return true;
    }
    int Front() { return count == 0 ? -1 : cq[front]; }
    bool isEmpty() { return count == 0; }
    bool isFull() { return count == size; }
};

// 10. Priority Queue
void priorityQueueDemo() {
    priority_queue<int> maxPQ;
    maxPQ.push(10); maxPQ.push(5);
    cout << "Top of Max-PQ: " << maxPQ.top() << endl;
}

// 11. Deque
void dequeDemo() {
    deque<int> dq;
    dq.push_back(1); dq.push_front(2);
    dq.pop_back();
    for (int x : dq) cout << x << " ";
    cout << endl;
}

//----------------------------------
// Main
//----------------------------------
int main() {
    cout << "Static Array:\n";
    staticArrayDemo();

    cout << "\nDynamic Array:\n";
    dynamicArrayDemo();

    cout << "\nSingly Linked List:\n";
    SLLNode* headSLL = new SLLNode(1);
    headSLL->next = new SLLNode(2);
    headSLL->next->next = new SLLNode(3);
    printSLL(headSLL);

    cout << "\nDoubly Linked List:\n";
    DLLNode* headDLL = new DLLNode(1);
    DLLNode* node2 = new DLLNode(2);
    headDLL->next = node2;
    node2->prev = headDLL;
    printDLL(headDLL);

    cout << "\nCircular Linked List:\n";
    CLLNode* headCLL = new CLLNode(1);
    headCLL->next = new CLLNode(2);
    headCLL->next->next = new CLLNode(3);
    headCLL->next->next->next = headCLL;
    printCLL(headCLL);

    cout << "\nStack (Array-based):\n";
    StackArray sa;
    sa.push(10); sa.push(20);
    cout << sa.top() << endl;
    sa.pop();
    cout << sa.top() << endl;

    cout << "\nStack (Linked List-based):\n";
    StackLL sll;
    sll.push(100); sll.push(200);
    cout << sll.top() << endl;
    sll.pop();
    cout << sll.top() << endl;

    cout << "\nQueue (Simple):\n";
    QueueArray qa;
    qa.enqueue(1); qa.enqueue(2);
    cout << qa.front() << endl;
    qa.dequeue();
    cout << qa.front() << endl;

    cout << "\nCircular Queue:\n";
    CircularQueue cq(3);
    cq.enqueue(1); cq.enqueue(2); cq.enqueue(3);
    cout << cq.Front() << endl;
    cq.dequeue();
    cout << cq.Front() << endl;

    cout << "\nPriority Queue:\n";
    priorityQueueDemo();

    cout << "\nDeque:\n";
    dequeDemo();

    return 0;
}
