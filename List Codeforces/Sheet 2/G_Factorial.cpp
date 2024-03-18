#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}
int main()
{
    ll x;
    cin >> x;
    while (x--)
    {
        ll n;
        cin >> n;
        ll fact = factorial(n);
        cout << fact << endl;
    }
    return 0;
}