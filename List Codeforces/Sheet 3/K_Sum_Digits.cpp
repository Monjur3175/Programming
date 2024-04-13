#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k, sum = 0;
    cin >> k;
    string s;
    cin >> s;
    for (ll i = 0; i < s.size(); i++)
    {
        sum+=s[i]-'0';
    }
    
    cout << sum << endl;

    return 0;
}