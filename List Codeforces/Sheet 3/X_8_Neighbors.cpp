#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void yes() { cout << "yes" << endl; }
void no() { cout << "no" << endl; }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, i, j;
    cin >> n >> m;
    char a[n][m];
    ll x, y;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    cin >> x >> y;
    x = x - 1;
    y = y - 1;
    if (a[x + 1][y] != '.' && a[x][y + 1] != '.' && a[x - 1][y] != '.' && a[x][y - 1] != '.' && a[x - 1][y - 1] != '.' && a[x + 1][y + 1] != '.' && a[x + 1][y - 1] != '.' && a[x - 1][y + 1] != '.')
    {
        yes();
    }
    else
    {
        no();
    }

    return 0;
}