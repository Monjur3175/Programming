#include <bits/stdc++.h>
using namespace std;

void backtrack(const vector<int>& S, int idx, int target, vector<int>& cur){
    if(target==0){
        cout << "{ ";
        for(size_t i=0;i<cur.size();++i) cout << cur[i] << (i+1<cur.size()? ", ":" ");
        cout << "}\n";
        return;
    }
    if(idx==(int)S.size() || target<0) return;
    // include
    cur.push_back(S[idx]);
    backtrack(S, idx+1, target - S[idx], cur);
    cur.pop_back();
    // exclude
    backtrack(S, idx+1, target, cur);
}

int main(){
    vector<int> S = {5,10,12,13,15,18};
    int d = 30;
    vector<int> cur;
    cout << "Subsets summing to " << d << ":\n";
    backtrack(S,0,d,cur);
}
