#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define MOD 1000000007
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long long ll;
const ll p = 2e5 + 10;
ll w[p];
void yes() { cout << "Yes" << endl; }
void no() { cout << "No" << endl; }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x, y, n = 0, t = 2;
    cin >> x >> y;
    ll p[x];
    while (t--)
    {
        for (ll i = 0; i < x; i++)
        {
            cin >> p[i];
            n = n + p[i];
        }
        if (n >= y)
        {
            yes();
        }
        else
        {
            no();
        }
    }

    return 0;
}