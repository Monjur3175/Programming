#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
int main()
{
    ll t, a, b, sum = 0, cnt = 0;
    cin >> t;
    while (t--)
    {
        int x = 1;
        int n;
        cin >> n;
        int arr[n];
        cin >> a >> b;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (ll i = 0; i < n; i++)
        {
            for (ll j = i; j < n; j++)
            {
                if (i == j)
                {
                    sum = arr[i] + arr[j];
                    if (sum >= a || sum <= b)
                    {
                        cnt++;
                    }
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}