#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define MOD 1000000007
#define pb push_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll p = 2e5 + 10;
const ll PI=3.14159;
ll w[p];
void yes(){cout << "YES" << endl;}
void no(){cout << "NO" << endl;}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1,s2;
    ll l1,l2;
    cin >> s1>>s2;
    for (ll i = 0; i < s1.size()-1; i++)
    {
        if (s1[i]<s1[i+1])
        {
            l1++;
        }
        else
        {
            break;
        }
        
    }
    for (ll i = 0; i < s2.size()-1; i++)
    {
        if (s2[i]<s2[i+1])
        {
            l2++;
        }
        else
        {
            break;
        }
    }
    if (l1>=l2)
    {
        cout<<s1<<endl; 
    }
    else
    {
        cout<<s2<<endl;
    }
    
    
return 0;
}