#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int factorial(int x)
{
    if (x > 1)
    {
        return x * factorial(x - 1);
    }
    else
    {
        return 1;
    }
}
int main()
{
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        cout << factorial(x) << endl;
    }

    return 0;
}