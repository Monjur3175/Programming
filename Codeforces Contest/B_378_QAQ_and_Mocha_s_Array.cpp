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
ll a[N];
void yes() { cout << "Yes" << endl; }
void no() { cout << "No" << endl; }

void solution()
{
    ll k;
    cin >> k;
    for (ll i = 0; i < k; i++)
    {
        cin >> a[i];
    }
    sort(a, a + k);
    ll w = 0, i = 1;
    for (; i < k; i++)
    {
        if (a[i] % a[0])
        {
            if (w)
            {
                if (a[i] % a[w])
                {
                    break;
                }
                else
                {
                    w = i;
                }
            }
        }
    }
    if (i >= k)
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
