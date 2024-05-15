#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin >> t;
    long long fac=1;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            fac*=i;
        }
        
        cout << fac << endl;
        fac=1;
    }

    return 0;
}