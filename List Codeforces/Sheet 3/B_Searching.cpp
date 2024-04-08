#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
ll w[N];

int main()
{
    ll x, u;
    cin >> x;
    for (ll i = 0; i < x; i++)
    {
        cin >> w[i];
    }
    cin >> u;
    bool found = false;
    for (ll i = 0; i < x; i++)
    {
        if (w[i] == u)
        {
            cout << i << endl;

            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << -1 << endl;
    }

    return 0;
}