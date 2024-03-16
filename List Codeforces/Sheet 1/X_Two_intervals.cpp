#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ll l1, l2, l3, l4;
    cin >> l1 >> l2 >> l3 >> l4;
    if ((l3 > l2 && l4 > l2) || (l3 < l1 && l4 < l1))
    {
        cout << "-1" << endl;
    }
    else
    {
        ll x, z;
        x = max(l1, l3);
        z = min(l2, l4);
        cout << x << " " << z << endl;
    }

    return 0;
}