#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
ll w[N];
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
int main()
{
    ll a, b, c, maximum, minimum;
    cin >> a >> b >> c;
    minimum = min({a, b, c});
    maximum = max({a, b, c});
    cout << minimum << " " << maximum << endl;

    return 0;
}