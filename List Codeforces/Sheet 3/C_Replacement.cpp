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
typedef long long ll;
const ll p = 2e5 + 10;
ll w[p];
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x;
    cin >> n;
    vll s;
    for (ll i = 0; i < n; i++)
    {
        cin >> x;
        s.pb(x);
        if (s[i] < 0)
        {
            cout << 2 << " ";
        }
        if (s[i] == 0)
        {
            cout << 0 << " ";
        }
        if (s[i] > 0)
        {
            cout << 1 << " ";
        }
    }

    return 0;
}