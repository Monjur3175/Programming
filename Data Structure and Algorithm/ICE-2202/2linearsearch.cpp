#include <iostream>
using namespace std;

int main()
{
    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter element to search: ";
    cin >> x;

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            cout << "Element found at position " << i + 1 << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Element not found!" << endl;
    return 0;
}
