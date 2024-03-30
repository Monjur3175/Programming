#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
ll w[N];
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
void solution()
{
    ll n;
    cin >> n;
    for (ll i = 0; i < 2 * n; i++)
    {
        for (ll j = 0; j < 2 * n; j++)
        {
            if ((i / 2 + j / 2) % 2 == 0)
            {
                cout << '#';
            }
            else
            {
                cout << '.';
            }
        }
        cout << endl;
    }
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}