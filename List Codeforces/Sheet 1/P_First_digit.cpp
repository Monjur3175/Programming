#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
ll w[N];
void yes() { cout << "EVEN" << endl; }
void no() { cout << "ODD" << endl; }
int main()
{
    ll a;
    cin >> a;
    while (a > 9)
    {
        a = a / 10;
    }
    if (a % 2 == 0)
    {
        yes();
    }
    else
    {
        no();
    }

    return 0;
}