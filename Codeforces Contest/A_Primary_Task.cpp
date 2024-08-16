#include <bits/stdc++.h>
using namespace std;

#define Monjur_Morshed (ios_base::sync_with_stdio(false), cin.tie(NULL));

typedef long long ll;

void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }

void solution()
{
    string x;
    cin >> x;
    if (x[0] == '1' && x[1] == '0' && (x[2] > 49 || (x[2] > 48 && x[3])))
    {
        yes();
    }
    else
    {
        no();
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
