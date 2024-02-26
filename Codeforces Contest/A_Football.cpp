#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
int main()
{
    ll n, goal = 0;
    cin >> n;
    string s, s1;
    for (ll i = 0; i < n; i++)
    {
        if (goal != 0)
        {
            cin >> s;
            if (s == s1)
            {
                goal += 1;
            }
            else
            {
                goal -= 1;
            }
        }
        else
        {
            cin >> s1;
            goal = 1;
        }
    }
    cout << s1 << endl;
    return 0;
}