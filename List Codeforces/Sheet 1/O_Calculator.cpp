#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
ll w[N];
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
int main()
{
    ll a, b;
    char s;
    cin >> a >> s >> b;

    if (s == '+')
    {
        cout << a + b << endl;
    }
    if (s == '-')
    {
        cout << a - b << endl;
    }
    if (s == '*')
    {
        cout << a * b << endl;
    }
    if (s == '/')
    {
        cout << a / b << endl;
    }

    return 0;
}