#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll p = 2e5 + 10;
ll w[p];
void yes() { cout << "Yes" << endl; }
void no() { cout << "No" << endl; }
bool stringpass(ll a, ll b,string s)
{
    if (s[a] != '-')
    {
        return false;
    }
    else if (s.size() != a + b + 1)
    {
        return false;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (i != a && !isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b;
    cin >> a >> b;
    cin.ignore();
    string s;
    cin >> s;
    if (stringpass(a, b, s))
    {
        yes();
    }
    else
    {
        no();
    }

    return 0;
}