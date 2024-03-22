#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
ll w[N];
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
int main()
{
    ll a;
    cin >> a;
    while (a--)
    {
        string s;
        cin >> s;
        for (ll i = s.size() - 1; i >= 0; i--)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }

    return 0;
}