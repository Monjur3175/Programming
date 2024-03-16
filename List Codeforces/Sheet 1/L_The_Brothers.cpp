#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
ll w[N];
void yes() { cout << "ARE Brothers" << endl; }
void no() { cout << "NOT" << endl; }
int main()
{
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    if (s2 == s4)
    {
        yes();
    }
    else
    {
        no();
    }
    return 0;
}