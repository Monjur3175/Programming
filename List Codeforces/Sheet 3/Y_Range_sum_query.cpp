#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q;
    cin >> n >> q;

    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    // Compute prefix sum
    vector<ll> prefix_sum(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }

    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        cout << prefix_sum[r] - prefix_sum[l - 1] << endl;
    }

    return 0;
}
