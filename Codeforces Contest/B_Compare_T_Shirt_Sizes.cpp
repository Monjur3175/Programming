#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define MOD 1000000007
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll p = 2e5 + 10;
ll w[p];
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }

void solution()
{
    string s1, s2;
    cin >> s1 >> s2;

    if (s1[s1.size() - 1] == 'S' && s2[s2.size() - 1] == 'S')
    {
        if (s1.size() == s2.size())
        {
            cout << "=" << endl;
        }
        if (s1.size() > s2.size())
        {
            cout << "<" << endl;
        }
        if (s1.size() < s2.size())
        {
            cout << ">" << endl;
        }
    }
    if (s1[s1.size() - 1] == 'S' && s2[s2.size() - 1] == 'M')
    {
        cout << "<" << endl;
    }
    if (s1[s1.size() - 1] == 'L' && s2[s2.size() - 1] == 'M')
    {
        cout << ">" << endl;
    }
    if (s1[s1.size() - 1] == 'M' && s2[s2.size() - 1] == 'S')
    {
        cout << ">" << endl;
    }
    if (s1[s1.size() - 1] == 'M' && s2[s2.size() - 1] == 'L')
    {
        cout << "<" << endl;
    }
    if (s1[s1.size() - 1] == 'L' && s2[s2.size() - 1] == 'L')
    {
        if (s1.size() == s2.size())
        {
            cout << "=" << endl;
        }
        if (s1.size() > s2.size())
        {
            cout << ">" << endl;
        }
        if (s1.size() < s2.size())
        {
            cout << "<" << endl;
        }
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
