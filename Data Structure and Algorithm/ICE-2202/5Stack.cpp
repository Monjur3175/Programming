#include <iostream>
using namespace std;

#define MAX 100 // Maximum size of stack

class Stack
{
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    // Push operation
    void push(int value)
    {
        if (top >= MAX - 1)
        {
            cout << "Stack Overflow!" << endl;
        }
        else
        {
            arr[++top] = value;
            cout << value << " pushed into stack." << endl;
        }
    }

    // Pop operation
    void pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow!" << endl;
        }
        else
        {
            cout << arr[top--] << " popped from stack." << endl;
        }
    }

    // Display operation
    void display()
    {
        if (top < 0)
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << "Stack elements are: " << endl;
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << endl;
            }
        }
    }
};

int main()
{
    Stack s;
    int choice, value;

    while (true)
    {
        cout << "\n--- Stack Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.display();
            break;

        case 4:
            cout << "Exiting program..." << endl;
            return 0;

        default:
            cout << "Invalid choice! Try again." << endl;
        }
    }
}
