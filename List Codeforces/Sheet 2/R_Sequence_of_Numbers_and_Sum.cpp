#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n, m, sum = 0;
    while (true)
    {
        cin >> n >> m;
        if (n <= 0 || m <= 0)
        {
            break;
        }

        ll x = max(n, m);
        ll y = min(n, m);
        for (ll i = y; i <= x; i++)
        {
            cout << i << " ";
            sum += i;
        }
        cout << "sum =" << sum;
        cout << endl;
        sum = 0;
    }
    return 0;
}