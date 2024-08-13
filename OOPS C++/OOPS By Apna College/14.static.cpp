#include <bits/stdc++.h>
using namespace std;
// void fun(){
//     static int x=0;
//     cout<<x<<endl;
//     x++;
// };
class person{
    public:
    person(){
        cout<<"Constructor"<<endl;
    }
    ~person(){
        cout<<"destructor"<<endl;
    }
};
int main()
{
    // fun();
    // fun();
    // fun();
    if (true)
    {
        static person obj;
    }
    cout<<"End of Main function"<<endl;
    return 0;
}