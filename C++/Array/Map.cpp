#include <bits/stdc++.h>
using namespace std;

#define Monjur_Morshed (ios_base::sync_with_stdio(false), cin.tie(NULL));

int main()
{
    Monjur_Morshed;
    map<int, string> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        string s;
        cin >> x >> s;
        mp.insert({x, s});
    }
    for (auto &pr : mp)
    {
        cout << pr.first << " " << pr.second << endl;
    }
    /*auto it=mp.find(2);
    if (it==mp.end())
    {
        cout<<"No Value"<<endl;
    }
    else
    {
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
    */
    return 0;
}
