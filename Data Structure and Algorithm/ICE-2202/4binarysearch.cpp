#include <iostream>
using namespace std;

int main()
{
    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter element to search: ";
    cin >> x;

    int low = 0, high = n - 1, mid;
    bool found = false;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            cout << "Element found at position " << mid + 1 << endl;
            found = true;
            break;
        }
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (!found)
        cout << "Element not found!" << endl;
    return 0;
}
