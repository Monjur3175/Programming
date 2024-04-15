#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll fibunacci(ll n)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    return fibunacci(n - 1) + fibunacci(n - 2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll result = fibunacci(n);
    cout << result << endl;
    return 0;
}