#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
void solution()
{
    ll x, y;
    cin >> x >> y;
    if (x > y)
    {
        cout << (x * 2) - 1 << endl;
    }
    else
    {
        cout << y * 2 - 1 << endl;
    }
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}