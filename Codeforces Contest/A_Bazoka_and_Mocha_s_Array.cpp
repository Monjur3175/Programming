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
void yes() { cout << "Yes" << endl; }
void no() { cout << "No" << endl; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        ll f = 0;
        for (ll i = 1; i <= n; i++)
        {
            cin >> w[i];
            if (w[i] < w[i - 1])
            {
                f++;
            }
        }
        if (w[n] > w[1])
        {
            f++;
        }
        cout << (f <= 1 ? "Yes" : "No") << endl;
    }
    return 0;
}
