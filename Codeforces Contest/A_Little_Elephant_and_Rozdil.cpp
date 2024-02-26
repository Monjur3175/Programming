#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
int main()
{
    ll n, cnt = 1, time, min_time = 1000000001, min_index = 0;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> time;
        if (time < min_time)
        {
            min_time = time;
            min_index = i;
            cnt = 1;
        }
        else if (time == min_time)
        {
            cnt++;
        }
    }
    if (cnt == 1)
    {
        cout << min_index << endl;
    }
    else
    {
        cout << "Still Rozdil" << endl;
    }

    return 0;
}