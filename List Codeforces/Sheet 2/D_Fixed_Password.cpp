#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
ll w[N];
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
int main()
{
    ll c = 1999;
    while (1)
    {
        ll x;
        cin >> x;
        if (x != c)
        {
            cout << "Wrong" << endl;
        }
        else
        {
            cout << "Correct" << endl;
            break;
        }
    }

    return 0;
}