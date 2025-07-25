#include <bits/stdc++.h>
using namespace std;


int main()
{
    vector<int> arr;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int target;
    cin>>target;
    int l=0,r=n-1;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (mid==target)
        {
            cout<<mid<<endl;
            break;
        }
        if (mid<target)
        {
            l=mid+1;
        }
        if (mid>target)
        {
            r=mid-1;
        }
    }
    
    
    
}