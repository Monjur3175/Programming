#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define MOD 1000000007
#define PI 3.141592653589793238
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define Monjur_Morshed (ios_base::sync_with_stdio(false), cin.tie(NULL));

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int, int> mii;
typedef pair<ll, ll> pll;
typedef set<ll> sll;
typedef string str;

void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }

void solution()
{
    ll n, m;
    ll l = INT_MIN;
    ll r = INF;
    cin >> n >> m;
    ll a[n], b[m];

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    ll bb = b[0];
    for (ll i = 0; i < n; i++)
    {
        if (bb - a[i] < a[i] && bb - a[i] >= l)
        {
            a[i] = bb - a[i];
        }
        l = a[i];
    }
    for (ll i = n - 1; i >= 0; i--)
    {
        if (bb - a[i] > a[i] && bb - a[i] <= r)
        {
            a[i] = bb - a[i];
        }
        r = a[i];
    }

    if (is_sorted(a, a + n))
    {
        yes();
    }
    else
    {
        no();
    }
}

int main()
{
    Monjur_Morshed;
    int t;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}