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
        res = res * i;
    return res;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll mypow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a);
        b /= 2;
        a = (a * a);
    }
    return ans;
}
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    for (ll i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}
ll nPr(ll n, ll r) { return fact(n) / fact(n - r); }
ll nCr(ll n, ll r) { return fact(n) / (fact(r) * fact(n - r)); }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }

void solution()
{
    ll n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (ll &i : x)
        cin >> i;
    for (ll &i : y)
        cin >> i;
    vector<pair<ll, ll>> q;
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n - 1; j++)
            if (x[j] > x[j + 1])
            {
                swap(x[j], x[j + 1]);
                q.push_back({1, j + 1});
            }
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n - 1; j++)
            if (y[j] > y[j + 1])
            {
                swap(y[j], y[j + 1]);
                q.push_back({2, j + 1});
            }
    for (ll i = 0; i < n; i++)
        if (x[i] > y[i])
        {
            swap(x[i], y[i]);
            q.push_back({3, i + 1});
        }
    cout << q.size() << '\n';
    for (auto &z : q)
        cout << z.first << ' ' << z.second << endl;
}

int main()
{
    Monjur_Morshed;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}
