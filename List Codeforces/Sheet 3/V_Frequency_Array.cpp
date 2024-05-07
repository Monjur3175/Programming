#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> cnt(m + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (ll i = 1; i <= m; i++)
    {
        cout << cnt[i] << endl;
    }

    return 0;
}