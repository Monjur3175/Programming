#include <bits/stdc++.h>
using namespace std;

void solution()
{
    int l, r, L, R;
    cin >> l >> r >> L >> R;
    cout << max(min(r, R) - max(l, L) - (l == L) - (r == R) + 1, 1 * 0) + 1 << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}