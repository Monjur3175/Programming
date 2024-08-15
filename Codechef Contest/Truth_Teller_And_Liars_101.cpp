#include <bits/stdc++.h>
using namespace std;
#define Monjur_Morshed (ios_base::sync_with_stdio(false), cin.tie(NULL));

void solution()
{
    int a, b;
    cin >> a >> b;
    if (a < b)
    {
        cout << -1 << endl;
    }
    else if (a > b)
    {
        cout << (2 * b + 1) << endl;
    }
    else
    {
        cout << -1 << endl;
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
