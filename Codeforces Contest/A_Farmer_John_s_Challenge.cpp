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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll N = 2e5 + 10;
ll w[N];
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }

void solution()
{
    ll n, k;
    cin >> n >> k;

    if (k == 1)
    {
        for (ll i = 1; i <= n; i++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else if (k == n)
    {
        for (ll i = 1; i <= n; i++)
        {
            cout << 1 << " ";
        }
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
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
