#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
ll w[N];
void yes(){cout << "YES" << endl;}
void no(){cout << "NO" << endl;}
int main() {
    ll n,m,sum=0;
    for (ll i = 0; i < 3; i++)
    {
        cin>>n>>m;
        if (n<=0&&m<=0)
        {
            break;
        }
        
       if (n<m&&n>0&&m>0)
       {
        for (ll i = n; i <= m; i++)
       {
        cout<<n<<" ";
        n++;
       sum=sum+n;
       }
       cout<<"sum ="<<sum;
       cout<<endl;
       }
       if (n>m&&n>0&&m>0)
       {
        for (ll i = m; i <= n; i++)
       {
        cout<<m<<" ";
        m++;
       }
       cout<<endl;
       }
       
       
       
    }
    
return 0;
}