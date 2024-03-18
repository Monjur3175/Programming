#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
int main()
{
    string s;
    cin >> s;
    string n1 = s;
    reverse(s.begin(), s.end());

    if (s == n1)
    {
        cout << n1 << endl;
        yes();
    }
    else
    {
        if (s[0] == '0')
        {
            int num = stoi(s);
            cout << num << endl;
            no();
        }
        else
        {
            cout << s << endl;
            no();
        }
    }

    return 0;
}