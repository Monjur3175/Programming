#include <bits/stdc++.h>
using namespace std;

class person{
    public:
    string name;
    int age;
    // person(){
    //     cout<<"I am parent Constructor"<<endl;
    // }
    person(string name,int age){
        this->name=name;
        this->age=age;
    }

};
class student:public person{
    public:
    int rollno;
    // student(){
    //     cout<<"I am Child Constructor"<<endl;
    // }
    student(string name,int age,int rollno):person(name,age){
        this->rollno=rollno;
    }
    void getInfo(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Roll No: "<<rollno<<endl;
    }
};
int main()
{
    student s1("Monjur",25,220601);
    // s1.name="Monjur";
    // s1.age=25;
    // s1.rollno=220601;
    s1.getInfo();
}
