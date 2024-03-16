#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void yes() { cout << "Yes" << endl; }
void no() { cout << "No" << endl; }
int main()
{
    int a, b, c, expected_result;
    char x, y;
    cin >> a >> x >> b >> y >> c;

    if (x == '+')
    {
        expected_result = a + b;
    }
    else if (x == '-')
    {
        expected_result = a - b;
    }
    else if (x == '*')
    {
        expected_result = a * b;
    }

    if (expected_result == c)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << expected_result << endl;
    }

    return 0;
}