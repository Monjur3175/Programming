#include <iostream>
using namespace std;

#define MAX 100

class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow! Cannot add more elements.\n";
            return;
        }

        if (front == -1)  // first element
            front = 0;

        arr[++rear] = x;
        cout << x << " added to the queue.\n";
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow! No elements to remove.\n";
            return;
        }

        cout << arr[front] << " removed from the queue.\n";
        front++;

        // Reset queue when empty
        if (front > rear)
            front = rear = -1;
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    cout << "---- Queue Operations ----\n";
    cout << "1. Enqueue (Add)\n";
    cout << "2. Dequeue (Remove)\n";
    cout << "3. Display\n";
    cout << "4. Exit\n";

    do {
        cout << "\nEnter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
