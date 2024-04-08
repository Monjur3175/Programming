#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
ll w[N];
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
int main()
{
    ll n, add = 0;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> w[i];
        add += w[i];
    }
    cout << abs(add) << endl;

    return 0;
}