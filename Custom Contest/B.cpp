#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void yes(){cout << "Right" << endl;}
void no(){cout << "Wrong" << endl;}
int main() {
    ll x,y;
    char c;
    cin >>x>>c>>y;
    
    
    if (c=='>')
    {
        if (x>y)
        {
            yes();
        }
        else
        {
            no();
        }
    }
    if (c=='<')
    {
        if (x<y)
        {
            yes();
        }
        else
        {
            no();
        }
    }
    if (c=='=')
    {
        if (x==y)
        {
            yes();
        }
        else
        {
            no();
        }
    }
return 0;
}