#include <bits/stdc++.h>
using namespace std;

vector<int> buildLPS(const string& p){
    int n = (int)p.size();
    vector<int> lps(n,0);
    for(int i=1,len=0;i<n;){
        if(p[i]==p[len]) lps[i++] = ++len;
        else if(len) len = lps[len-1];
        else lps[i++] = 0;
    }
    return lps;
}

vector<int> kmpSearch(const string& text, const string& pat){
    if(pat.empty()) return {};
    vector<int> lps = buildLPS(pat), pos;
    for(int i=0,j=0;i<(int)text.size();){
        if(text[i]==pat[j]){ i++; j++; if(j==(int)pat.size()){ pos.push_back(i-j); j=lps[j-1]; } }
        else if(j) j = lps[j-1];
        else i++;
    }
    return pos; // starting indices (0-based)
}

int main(){
    string text="ababcabcabababd", pat="ababd";
    auto res = kmpSearch(text,pat);
    for(int i: res) cout << "Match at index " << i << '\n';
}
