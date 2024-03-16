#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
ll w[N];
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
int main()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    a %= 100;
    b %= 100;
    c %= 100;
    d %= 100;
    ll x = (a * b * c * d) % 100;
    if (x <= 9)
    {
        cout << 0 << x << endl;
    }
    else
    {
        cout << x << endl;
    }
    return 0;
}