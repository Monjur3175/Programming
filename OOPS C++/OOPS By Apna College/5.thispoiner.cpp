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
    void getInfo(){
        cout<<name<<endl;
        cout<<subject<<endl;
    }
};

int main()
{
    teacher t1={"Monjur","C++","ICE"};
    t1.getInfo();
    return 0;
}
