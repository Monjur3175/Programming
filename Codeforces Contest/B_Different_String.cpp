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
    string s;
    ll x = 0;
    cin >> s;
    for (ll i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            x++;
        }
        if (s[i] != s[i + 1])
        {
            swap(s[i], s[i + 1]);
        }
    }
    if (x == s.size() - 1)
    {
        no();
    }
    else if (x != s.size())
    {
        yes();
        cout << s << endl;
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