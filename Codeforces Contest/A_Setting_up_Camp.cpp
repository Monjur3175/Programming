#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solution()
{
    ll a, b, c, x, cnt = 0;
    cin >> a >> b >> c;
    if ((b + c) % 3 > c)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << a + (b + c + 2) / 3 << endl;
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