#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a[16], n = 16;
        vector<int> v;
        for (int i = 0; i < 16; i++)
        {
            cin >> a[i];
            v.push_back(a[i]);
        }
        sort(v.begin(), v.end());
        map<int, int> mp;
        mp = {{0, 0}, {1, 1}, {2, 1}, {3, 2}, {4, 2}, {5, 2}, {6, 2}, {7, 3}, {8, 3}, {9, 3}, {10, 3}, {11, 3}, {12, 3}, {13, 3}, {14, 3}, {15, 4}};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i] == v[j])
                {
                    cout << mp[j] << " ";
                }
            }
        }
        cout << endl;
    }
}