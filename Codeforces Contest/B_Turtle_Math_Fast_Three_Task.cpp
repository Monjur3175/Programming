#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
ll w[N];
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
void solution()
{
    ll n, s = 0, f = 0;
    cin >> n;
    ll a;
    for (ll i = 0; i < n; i++)
    {
        cin >> a;
        s += a;
        if (a % 3 == 1)
        {
            f = 1;
        }
    }
    if (s % 3 == 0)
    {
        cout << "0" << endl;
    }
    else if (s % 3 == 2)
    {
        cout << "1" << endl;
    }
    else if (f)
    {
        cout << "1" << endl;
    }
    else
    {
        cout << "2" << endl;
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