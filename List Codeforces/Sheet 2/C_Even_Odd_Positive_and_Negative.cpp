#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
ll w[N];
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
int main()
{
    ll x, even = 0, odd = 0, positive = 0, negative = 0;
    cin >> x;
    for (ll i = 0; i < x; i++)
    {
        cin >> w[i];
    }
    for (ll i = 0; i < x; i++)
    {
        if (w[i] % 2 == 0)
        {
            even++;
        }
        if (w[i] % 2 != 0)
        {
            odd++;
        }
        if (w[i] > 0)
        {
            positive++;
        }
        if (w[i] < 0)
        {
            negative++;
        }
    }
    cout << "Even: " << even << endl;
    cout << "Odd: " << odd << endl;
    cout << "Positive: " << positive << endl;
    cout << "Negative: " << negative << endl;
    return 0;
}