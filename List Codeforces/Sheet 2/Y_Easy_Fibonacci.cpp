#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll N, t1 = 0, t2 = 1, next = 0;
    cin >> N;
    for (ll i = 1; i <= N; i++)
    {
        if (i == 1)
        {
            cout << t1 << " ";
            continue;
        }
        if (i == 2)
        {
            cout << t2 << " ";
            continue;
        }
        next = t1 + t2;
        t1 = t2;
        t2 = next;
        cout << next << " ";
    }

    return 0;
}