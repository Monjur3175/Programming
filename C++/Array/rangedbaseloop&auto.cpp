#include <bits/stdc++.h>
using namespace std;

#define Monjur_Morshed (ios_base:: sync_with_stdio(false),cin.tie(NULL));

void solution()
{
    vector<int>v;
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        v.push_back(x);
    }
    for(auto &value:v){
        cout<<value<<" ";
    }
    cout<<endl;
}

int main()
{
    Monjur_Morshed;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}
