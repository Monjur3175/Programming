#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll digitsum(ll num)
{
    ll sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
int main()
{
    ll N, A, B, aum = 0, add = 0;
    cin >> N >> A >> B;

    for (ll i = 1; i <= N; i++)
    {
        ll aum = digitsum(i);
        if (aum >= A && aum <= B)
        {
            add += i;
        }
    }

    cout << add << endl;
    return 0;
}