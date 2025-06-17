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

const ll Q = 2e5 + 10;
ll w[Q];

ll fact(ll n)
{
    if (n == 0)
        return 1;
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res *= i;
    return res;
}

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

ll power(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans *= a;
        a *= a;
        b /= 2;
    }
    return ans;
}

bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (n < 2)
    {
        no();
        return;
    }

    int d = a[1] - a[0];

    for (int i = 1; i < n - 1; i++)
    {
        if (a[i + 1] - a[i] != d)
        {
            no();
            return;
        }
    }

    if (abs(a[0] + n * d) % (n + 1) || (a[0] + n * d) < 0 || (a[0] - d) < 0)
        no();
    else
        yes();
}

int main()
{
    Monjur_Morshed;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
