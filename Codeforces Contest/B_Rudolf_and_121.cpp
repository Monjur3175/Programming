#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
ll w[N];
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
void solution()
{
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll l = 0, r = n - 1;
    while (a[l] >= 0 && l <= r - 2)
    {
        a[l + 1] -= 2 * a[l];
        a[l + 2] -= a[l];
        a[l] = 0;
        l++;
    }
    if (l == r - 1 && a[l] == 0 && a[r] == 0)
    {
        yes();
    }
    else
    {
        no();
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