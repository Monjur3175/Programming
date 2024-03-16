#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
ll w[N];
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
int main()
{
    float N;
    cin >> N;
    if (N - (int)N > 0)
    {
        cout << "float " << (int)N << " ";
        cout << fixed << setprecision(3) << N - ((int)N) << endl;
    }
    else
    {
        cout << "int " << int(N) << endl;
    }
    return 0;
}