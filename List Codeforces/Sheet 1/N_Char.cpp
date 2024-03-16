#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
ll w[N];
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
int main()
{
    char s;
    cin >> s;
    if (islower(s))
    {
        s = toupper(s);
    }
    else
    {
        s = tolower(s);
    }
    cout << s << endl;
    return 0;
}