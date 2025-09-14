#include <iostream>
using namespace std;
#define MAX 100

class Queue
{
  int arr[MAX], front, rear;

public:
  Queue() { front = rear = -1; }
  void enqueue(int x)
  {
    if (rear == MAX - 1)
      cout << "Queue Overflow\n";
    else
    {
      if (front == -1)
        front = 0;
      arr[++rear] = x;
    }
  }
  void dequeue()
  {
    if (front == -1 || front > rear)
      cout << "Queue Underflow\n";
    else
      cout << "Dequeued: " << arr[front++] << endl;
  }
  void display()
  {
    if (front == -1 || front > rear)
      cout << "Queue is empty\n";
    else
    {
      cout << "Queue elements: ";
      for (int i = front; i <= rear; i++)
        cout << arr[i] << " ";
      cout << endl;
    }
  }
};

int main()
{
  Queue q;
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.display();
  q.dequeue();
  q.display();
  return 0;
}
