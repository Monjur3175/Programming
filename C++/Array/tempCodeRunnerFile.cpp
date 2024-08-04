#include <bits/stdc++.h>
using namespace std;

#define Monjur_Morshed (ios_base:: sync_with_stdio(false),cin.tie(NULL));

void print(set<string>&s){
    for(auto value:s){
        cout<<value<<endl;
    }
}
int main()
{
    Monjur_Morshed;
    set<string>s;
    s.insert("abc");
    s.insert("bcd");
    s.insert("efg");
    print(s);
    return 0;
}
