#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
ll w[N];
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll sum = 0;
        ll x, y;
        cin >> x >> y;
        ll a = min(x, y);
        ll b = max(x, y);
        for (ll i = a; i <= b; i++)
        {
            if (i % 2 != 0 && i != a && i != b)
            {
                sum += i;
            }
        }
        cout << sum << endl;
    }
    return 0;
}