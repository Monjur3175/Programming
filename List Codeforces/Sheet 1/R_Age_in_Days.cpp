#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
ll w[N];
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
int main()
{
    ll x;
    cin >> x;
    int year = x / 365;
    x = x % 365;
    int month = x / 30;
    x = x % 30;
    int day = x;
    cout << year << " years" << endl;
    cout << month << " months" << endl;
    cout << day << " days" << endl;
    return 0;
}