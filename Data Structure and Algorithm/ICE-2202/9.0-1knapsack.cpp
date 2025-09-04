#include <bits/stdc++.h>
using namespace std;

struct Item{int w,p;};

int main(){
    vector<Item> it = {{2,15},{6,25},{12,13},{9,23}}; // (w,p) pairs
    int n = (int)it.size(), C = 20;

    vector<vector<int>> dp(n+1, vector<int>(C+1,0));
    for(int i=1;i<=n;i++){
        for(int c=0;c<=C;c++){
            dp[i][c] = dp[i-1][c];
            if(it[i-1].w<=c)
                dp[i][c] = max(dp[i][c], it[i-1].p + dp[i-1][c - it[i-1].w]);
        }
    }
    cout << "Maximum profit: " << dp[n][C] << '\n';

    // reconstruct chosen items (indices 1..n)
    vector<int> chosen;
    int c=C;
    for(int i=n;i>=1;i--){
        if(dp[i][c]!=dp[i-1][c]){
            chosen.push_back(i); // item i chosen
            c -= it[i-1].w;
        }
    }
    reverse(chosen.begin(), chosen.end());
    cout << "Chosen item indices: ";
    for(int id: chosen) cout << id << ' ';
    cout << '\n';
}
