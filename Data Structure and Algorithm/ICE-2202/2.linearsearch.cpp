#include <bits/stdc++.h>
using namespace std;

int linearSearch(const vector<int> &a, int key)
{
    for (size_t i = 0; i < a.size(); ++i)
        if (a[i] == key)
            return (int)i;
    return -1;
}

int main()
{
    vector<int> a ;
    cout<<"Enter the Number of Element"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the element"<<endl;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    int key = 12;
    int idx = linearSearch(a, key);
    if (idx != -1)
        cout << "Found at index " << idx << '\n';
    else
        cout << "Not found\n";
}
