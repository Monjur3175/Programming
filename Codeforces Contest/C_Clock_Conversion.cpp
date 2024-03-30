#include <bits/stdc++.h>
using namespace std;

void solution()
{
    int a, b;
    char h;
    cin >> a >> h >> b;
    if (a >= 13 && b >= 0)
    {
        cout << setw(2) << setfill('0') << a - 12 << h << setw(2) << setfill('0') << b << " PM" << endl;
    }
    else if (a == 0)
    {
        cout << setw(2) << setfill('0') << a + 12 << h << setw(2) << setfill('0') << b << " AM" << endl;
    }
    else if (a == 12 && b >= 0)
    {
        cout << setw(2) << setfill('0') << a << h << setw(2) << setfill('0') << b << " PM" << endl;
    }

    else
    {
        cout << setw(2) << setfill('0') << a << h << setw(2) << setfill('0') << b << " AM" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}
