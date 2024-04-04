#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ll k, s, z;
    cin >> k >> s;
    ll cnt = 0;
    for (ll i = 0; i <= k; i++)
    {
        for (ll j = 0; j <= k; j++)
        {
            z = s - i - j;
            if (z >= 0 && z <= k)
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}