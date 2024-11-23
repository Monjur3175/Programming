#include <bits/stdc++.h>
using namespace std;

class teacher{
    public:
    //properties / attributes
    string name;
    string subject;
    string dept;
    //Constructor
    teacher(){
        cout<<"Hi!,I am a Constructor"<<endl;
        dept="ICE";
    }
};
int main()
{
    teacher t1;//Constructor called Automatically
    t1.name="Monjur";
    t1.subject="C++";
    //t1.dept="ICE";
    cout<<t1.name<<endl;
    cout<<t1.dept<<endl;
    return 0;
}
