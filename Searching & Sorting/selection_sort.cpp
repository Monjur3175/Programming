#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr;
    int arr_length;
    cout << "Enter the length of the array" << endl;
    cin >> arr_length;
    cout << "Enter the Elements of the array" << endl;
    for (int i = 0; i < arr_length; i++)
    {
        cin >> arr[i];
    }
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
    cout << "Selection Sort: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
