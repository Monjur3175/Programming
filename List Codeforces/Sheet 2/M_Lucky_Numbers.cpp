#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }

bool islucky(int i)
{
    string numstr = to_string(i);
    for (char digit : numstr)
    {
        if (!isdigit(digit) || digit != '4' && digit != '7')
        {
            return false;
        }
    }
    return true;
}

void luckynumbers(int a, int b)
{
    bool foundlucky = false;
    for (ll i = a; i <= b; i++)
    {
        if (islucky(i))
        {
            cout << i << " ";
            foundlucky = true;
        }
    }
    if (!foundlucky)
    {
        cout << -1;
    }
    cout << endl;
}

int main()
{
    ll a, b;
    cin >> a >> b;
    luckynumbers(a, b);
    return 0;
}