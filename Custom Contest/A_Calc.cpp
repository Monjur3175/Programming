#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
int main()
{
    ll x, y;
    cin >> x >> y;
    cout << x << " "
         << "+"
         << " " << y << " ="
         << " " << x + y << endl;
    cout << x << " "
         << "*"
         << " " << y << " ="
         << " " << x * y << endl;
    cout << x << " "
         << "-"
         << " " << y << " ="
         << " " << x - y << endl;
    return 0;
}