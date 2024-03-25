#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    for (ll i = 1; i <= N; i++)
    {
        // leading spaces prints in first loop
        for (ll j = 1; j <= N - i; j++)
        {
            cout << " ";
        }
        cout << endl;
        // in this loop * is printed
        for (ll k = 1; k <= 2 * i - 1; k++)
        {
            cout << "*";
        }
    }
    return 0;
}