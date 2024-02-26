#include <bits/stdc++.h>
using namespace std;

typedef int ll;
void yes(){cout << "YES" << endl;}
void no(){cout << "NO" << endl;}
void solution()
{
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    ll v=a[0];
    for (ll i = 1; i < n; i++)
    {
       v^=a[i];
    }
    
   
    cout<<v<<endl;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}