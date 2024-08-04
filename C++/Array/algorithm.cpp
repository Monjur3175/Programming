#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define MOD 1000000007
#define PI 3.141592653589793238
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()//random
#define Monjur_Morshed (ios_base:: sync_with_stdio(false),cin.tie(NULL));

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll Q = 2e5 + 10;
ll w[Q];
ll fact(ll n)          { if(n==0) return 1; ll res = 1; for (ll i = 2; i <= n; i++) res = res * i; return res; }
ll gcd(ll a, ll b)     { if (b == 0) return a; return gcd(b, a % b); }
ll mypow(ll a, ll b)   { ll ans = 1; while(b){ if (b&1) ans = (ans*a) ; b /= 2; a = (a*a); } return ans; }
bool isPrime(ll n)     { if(n <= 1) return false; for(ll i = 2; i <= sqrt(n); i++) if(n % i == 0) return false; return true; }
ll nPr(ll n, ll r)     { return fact(n) / fact(n - r); }
ll nCr(ll n, ll r)     { return fact(n) / (fact(r) * fact(n - r)); }
ll lcm(ll a, ll b)     { return (a * b) / gcd(a, b);}
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }

void solution()
{
    vll a;
    ll n;
    cin>>n;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin>>x;
        a.pb(x);
    }
    ll min=*min_element(all(a));
    cout<<"Min:"<<min<<endl;
    ll max=*max_element(all(a));
    cout<<"Max:"<<max<<endl;
    ll sum=accumulate(all(a),0);
    cout<<"Sum:"<<sum<<endl;
    ll cnt=count(all(a),5);
    cout<<"Count:"<<cnt<<endl;
    auto it=find(all(a),5);
    if (it!=a.end())
    {
        cout<<"Found:";
        cout<<*it<<endl;
    }
    cout<<"Reversed"<<endl;
    reverse(all(a));
    for (ll i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
    
    
}

int main()
{
    Monjur_Morshed;
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}
