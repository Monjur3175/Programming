#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll x, y, gcd;
    cin >> x >> y;
    gcd = min(x, y);
    while (gcd > 0)
    {
        if (x % gcd == 0 && y % gcd == 0)
        {
            break;
        }
        gcd--;
    }
    cout << gcd << endl;
    return 0;
}