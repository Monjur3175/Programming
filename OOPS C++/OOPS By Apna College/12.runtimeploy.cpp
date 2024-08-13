#include <bits/stdc++.h>
using namespace std;

class parent{
    public:
    virtual void hello(){
        cout<<"Hello from parent"<<endl;
    }
};
class child:public parent{
    public:
    //virtual function
    void hello(){
        cout<<"Hello from child"<<endl;
    }
};

int main()
{
    child c1;
    c1.hello();
    return 0;
}
