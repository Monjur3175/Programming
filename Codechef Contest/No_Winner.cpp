#include <bits/stdc++.h>
using namespace std;

#define Monjur_Morshed (ios_base::sync_with_stdio(false), cin.tie(NULL));
typedef long long ll;
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }

void solution()
{
    ll a, b, c, m;
    cin >> a >> b >> c >> m;
    ll x = abs(a - b);
    ll y = abs(a - c);
    ll z = abs(b - c);
    if (x <= m || y <= m || z <= m)
    {
        yes();
    }
    else
    {
        no();
    }
}

int main()
{
    Monjur_Morshed;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}
