#include <iostream>
using namespace std;
void bubbleshort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        cout << " pass " << i + 1 << ": ";
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }

        cout << endl;
    }
}
int main()
{

    int n;
    cout << "enetr the  number of element :";
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bubbleshort(arr, n);
    cout << "sorted array :";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<" ";
    }

    cout << endl;
    delete[] arr;
    return 0;
}