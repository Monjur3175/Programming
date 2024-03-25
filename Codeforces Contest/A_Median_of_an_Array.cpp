#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
ll w[N];
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
void solution()
{
    ll n, x = 0;
    cin >> n;
    ll a[n];
    ll k = n / 2 + n % 2;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    ll b = upper_bound(a + 1, a + n + 1, a[k]) - a;
    cout<<b<<endl;
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