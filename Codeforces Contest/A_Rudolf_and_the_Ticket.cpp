#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
ll w[N], b[N], c[N];
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
void solution()
{
    ll n, m, k, x = 0;
    cin >> n >> m >> k;
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (ll j = 0; j < m; j++)
    {
        cin >> c[j];
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (b[i] + c[j] <= k)
            {
                x++;
            }
        }
    }
    cout << x << endl;
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