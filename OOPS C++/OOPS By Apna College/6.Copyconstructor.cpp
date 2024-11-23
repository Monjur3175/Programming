#include <bits/stdc++.h>
using namespace std;

class teacher{
    public:
    string name;
    string subject;
    string dept;
    //non-paramiterized
    teacher(){
        cout<<"Hi!,I am a Constructor"<<endl;
        dept="ICE";
    }
    //paramiterized
    teacher(string name,string subject,string dept){
        this->name=name;
        this->subject=subject;
        this->dept=dept;
        //first one is object,second one is parameter
    }
    //copy constructor
    teacher(teacher &orgobj){ //pass by reference
        this->name=orgobj.name;
        this->subject=orgobj.subject;
        this->dept=orgobj.dept;
        cout<<"I am Custom Copy Constructor"<<endl;
    }
    void getInfo(){
        cout<<name<<endl;
        cout<<subject<<endl;
    }
};

int main()
{
    teacher t1={"Monjur","C++","ICE"};
    teacher t2=t1;//copy custom constructor ->invoked
    t2.getInfo();
    return 0;
}