#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
ll w[N];
void yes() { cout << "Multiples" << endl; }
void no() { cout << "No Multiples" << endl; }
int main()
{
    ll a, b;
    cin >> a >> b;
    if (b % a == 0)
    {
        yes();
    }
    else if (a % b == 0)
    {
        yes();
    }
    else
    {
        no();
    }
    return 0;
}