#include <bits/stdc++.h>
#include <ratio>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node(int d) {
    data = d;
    next = nullptr;
  }
};
class Queue {
  Node *head, *tail;

public:
  Queue() {
    head = nullptr;
    tail = nullptr;
  }
  void add(int d) {
    Node *newnode = new Node(d);
    if (tail == nullptr) {
      head = newnode;
      tail = newnode;
    } else {
      tail->next = newnode;
      tail = tail->next;
    }
  }
  int remove() {
    if (head == nullptr)
      return -1;
    int data = head->data;
    Node *temp;
    temp = head;
    head = head->next;
    delete temp;
    return data;
  }
  void print() {
    Node *current = head;
    while (current != nullptr) {
      cout << current->data << "->";
      current = current->next;
    }
    cout << endl;
  }
};

int main() {
  Queue q;
  for (int i = 0; i < 10; i++) {
    q.add(i);
    q.print();
  }
  for (int i = 0; i < 10; i++) {
    q.remove();
    q.print();
  }
}
