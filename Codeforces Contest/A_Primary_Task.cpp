#include <bits/stdc++.h>
using namespace std;

#define Monjur_Morshed (ios_base::sync_with_stdio(false), cin.tie(NULL));

typedef long long ll;

void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }

void solution()
{
    ll s;
    cin >> s;
    ll n = s;
    while (s > 100)
    {
        s = s / 10;
    }
    cout<<s<<endl;
    n = n % 100;
    if (s > 10 || n == 1)
    {
        no();
    }
    else
    {
        yes();
    }
}

int main()
{
    Monjur_Morshed;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}
