#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void yes(){cout << "YES" << endl;}
void no(){cout << "NO" << endl;}
int main() {
    ll n,x;
    cin>>n>>x;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            if (a[i]+a[j]==x)
            {
                cout<<i<<" "<<j<<endl;
                break;
            }
            else
            {
                cout<<"IMPOSSIBLE"<<endl;
                break;
            }
            
        }
        
        
    }
    
    
return 0;
}