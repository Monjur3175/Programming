#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define MOD 1000000007
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll p = 2e5 + 10;
ll w[p];
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }

void solution()
{
    ll n, x = 0;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    for (ll i = 0; i < n; i++)
    {
        if (w[i] == w[i + 1])
        {
            x = w[i];
        }
    }
    for (ll i = 0; i < n; i++)
    {
        if (w[i] != x)
        {
            cout << i + 1 << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}
