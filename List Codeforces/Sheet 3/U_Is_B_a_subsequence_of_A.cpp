#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define MOD 1000000007
#define pb push_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<double> vd;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long long ll;
const ll p = 2e5 + 10;
ll w[p];
void yes(){cout << "YES" << endl;}
void no(){cout << "NO" << endl;}
bool subseq(const vll& a,const vll& b)
{
    ll N=a.size(),M=b.size();
    ll i=0,j=0;
    while (i<N && j<M)
    {
        if (a[i]==b[j])
        {
            j++;
        }
        i++;
    }
    return j==M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin >> n>>m;
    vll a(n),b(m);
    for (ll i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    if (subseq(a,b))
    {
        yes();
    }
    else
    {
        no();
    }
    
    
return 0;
}