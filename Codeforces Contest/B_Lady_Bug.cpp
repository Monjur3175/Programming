#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define MOD 1000000007
#define PI 3.141592653589793238
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define Monjur_Morshed (ios_base::sync_with_stdio(false), cin.tie(NULL));

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int, int> mii;
typedef pair<ll, ll> pll;
typedef set<ll> sll;
typedef string str;

const ll Q = 2e5 + 10;

void solution() {
    ll n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    // Count the number of 1s in both strings
    ll cntA = count(all(a), '1');
    ll cntB = count(all(b), '1');

    // If both strings have the same number of 1s, it's possible to make 'a' all zeros
    if (cntA == cntB) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    Monjur_Morshed;
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}