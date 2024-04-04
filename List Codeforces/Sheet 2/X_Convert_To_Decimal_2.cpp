#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define MOD 1000000007
#define pb push_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll N = 2e5 + 10;
ll w[N];
void yes(){cout << "YES" << endl;}
void no(){cout << "NO" << endl;}

ll countones(ll n)
{
    string binary_str = bitset<32>(n).to_string();
    int ones_count = 0;
    for (char c : binary_str) {
        if (c == '1') {
            ones_count++;
        }
    }
    return stoi(string(ones_count, '1'), nullptr, 2);
}
void solution() {
    ll n;
    cin>>n;
    cout<<countones(n)<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t; 
    while (t--) {
        solution();
    }
    return 0;
}
