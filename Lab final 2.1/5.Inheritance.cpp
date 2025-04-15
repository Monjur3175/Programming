#include <bits/stdc++.h>
using namespace std;
class x{
    public:
    int area(int l,int w){
        return l*w;
    }
};
class y:public x{
    public:
    int volume(int l,int w,int h)
    {
        int v=area(l,w)*h;
        return v;
    }
};
int main()
{
    y j;
    int a,b,c;
    cout<<"Enter 3 Numbers:"<<endl;
    cin>>a>>b>>c;
    cout<<j.volume(a,b,c)<<endl;
}
