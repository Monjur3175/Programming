#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
int main()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b >= c)
    {

        cout << c << " " << b << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}