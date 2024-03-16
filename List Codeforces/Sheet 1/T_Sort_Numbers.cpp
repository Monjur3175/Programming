#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    ll ax[] = {a, b, c};

    sort(ax, ax + 3);
    for (ll i = 0; i < 3; i++)
    {
        cout << ax[i] << endl;
    }
    cout << endl;
    cout << a << endl
         << b << endl
         << c << endl;

    return 0;
}