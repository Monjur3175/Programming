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
        ll a, b, c;
        cin >> a >> b >> c;
        if (a < b && b < c)
        {
            cout << "STAIR" << endl;
        }
        else if (a < b && b > c)
        {
            cout << "PEAK" << endl;
        }
        else
        {
            cout << "NONE" << endl;
        }
    }

    return 0;
}