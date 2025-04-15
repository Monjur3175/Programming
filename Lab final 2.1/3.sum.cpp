#include <bits/stdc++.h>
using namespace std;
class x{
    public:
    int q(int a,int b,int c){
        return a+b+c;
    }
    void r(){
        int x,y,z;
        cout<<"Enter three Numbers"<<endl;
        cin>>x>>y>>z;
        int u=q(x,y,z);
        cout<<"The sum of the three number is:"<<u<<endl;
    }
};

int main()
{
    x m1;
    m1.r();
    return 0;
}
