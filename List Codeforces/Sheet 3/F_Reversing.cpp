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
typedef long long ll;
const ll p = 2e5 + 10;
ll w[p];
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    for (ll i = n - 1; i >= 0; i--)
    {
        cout << w[i] << " ";
    }

    return 0;
}