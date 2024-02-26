#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
int main()
{
    ll x, y;
    ll xlast_digit=11;
    ll ylast_digit=11;
    cin >> x >> y;

    while (xlast_digit >= 10)
    {
        x / 10;
        xlast_digit = x % 10;
    }
    while (ylast_digit >= 10)
    {
        y / 10;
        ylast_digit = y % 10;
    }

    cout << xlast_digit + ylast_digit << endl;
    return 0;
}