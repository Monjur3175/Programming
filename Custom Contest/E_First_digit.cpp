#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void yes(){cout << "EVEN" << endl;}
void no(){cout << "ODD" << endl;}
int main() {
    ll x;
    cin >>x ;
    while (x>=10)
    {
        x=x/10;
    }
    
    if (x%2==0)
    {
        yes();
    }
    else
    {
        no();
    }
    
    
return 0;
}