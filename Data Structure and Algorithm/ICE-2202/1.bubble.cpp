#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &a)
{
    int n = (int)a.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

int main()
{
    vector<int> a;
    cout << "Enter the Number of Element" << endl;
    int n;
    cin >> n;
    cout << "Enter the element" << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    bubbleSort(a);
    for (int x : a)
        cout << x << ' ';
    cout << '\n';
}
