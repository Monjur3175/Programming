#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define Monjur_Morshed (ios_base:: sync_with_stdio(false),cin.tie(NULL));

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll Q = 2e5 + 10;

void printVec(vi &v){
    cout<<v.size()<<endl;
    for (ll i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}


int main()
{
    Monjur_Morshed;
    int N;
    cin>>N;
    vector<vi>v;
    for (ll i = 0; i < N; i++)
    {
        ll n;
        cin>>n;
        vi temp;
        for (ll j = 0; j < n; j++)
        {
            ll x;
            cin>>x;
            temp.pb(x);
        }
        v.pb(temp);
    }
    for (ll i = 0; i < v.size(); i++)
    {
        printVec(v[i]);
    }
    return 0;
}
