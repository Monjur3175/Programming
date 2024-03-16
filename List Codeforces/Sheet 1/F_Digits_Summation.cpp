#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
ll w[N];
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }

int main()
{
    ll n, m;
    cin >> n >> m;
    n = n % 10;
    m = m % 10;
    cout << n + m << endl;
    return 0;
}