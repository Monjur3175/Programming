/*given t test cases and in each test cases a number given n print it's factorial for each test case %M where M=10^9+7
constrains
1<=T<=10^5
1<=N<=10^5
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int M = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll fact = 1;
        for (ll i = 2; i <= n; i++)
        {
            fact = (fact * i) % M;
        }
        cout << fact << endl;
    }

    return 0;
}