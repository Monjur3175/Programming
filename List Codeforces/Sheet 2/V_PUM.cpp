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
    for (ll j = 1; j <= n * 4; j += 4)
    {
        cout << j << " " << j + 1 << " " << j + 2 << " "
             << "PUM" << endl;
    }

    return 0;
}
