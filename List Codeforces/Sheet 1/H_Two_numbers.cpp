#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
ll w[N];
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
int main()
{
    float a, b;
    cin >> a >> b;

    cout << "floor"
         << " " << a << " / " << b << " = " << floor(a / b) << endl;
    cout << "ceil"
         << " " << a << " / " << b << " = " << ceil(a / b) << endl;
    cout << "round"
         << " " << a << " / " << b << " = " << round(a / b) << endl;

    return 0;
}