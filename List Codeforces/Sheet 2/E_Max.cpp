#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
ll w[N];
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
int main()
{
    ll n;
    cin >> n;
    ll a[n], maximum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        if (a[i] > maximum)
        {
            maximum = a[i];
        }
    }
    cout << maximum << endl;

    return 0;
}