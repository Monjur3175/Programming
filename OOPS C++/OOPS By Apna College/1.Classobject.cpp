#include <bits/stdc++.h>
using namespace std;

class teacher{
    private:
    double salary;
    public:
    //properties / attributes
    string name;
    string subject;
    string dept;
    //methods / member function
    void changedept(string newDept){
        dept=newDept; 
    }
    //setter
    void setSalary(double s){
        salary=s;
    }
    //getter
    double getSalary(){
        return salary;
    }
};

int main()
{
    teacher t1;
    t1.name="Monjur";
    t1.subject="C++";
    t1.dept="ICE";
    t1.setSalary(25000);
    cout<<t1.name<<endl;
    cout<<t1.getSalary()<<endl;
    return 0;
}