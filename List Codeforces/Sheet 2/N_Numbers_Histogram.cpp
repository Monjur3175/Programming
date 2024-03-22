#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
ll w[N];
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
int main()
{
    char plus;
    cin >> plus;
    ll x, a;
    cin >> x;

    for (ll i = 0; i < x; i++)
    {
        cin >> a;
        for (ll i = 0; i < a; i++)
        {
            cout << plus;
        }

        cout << endl;
    }

    return 0;
}