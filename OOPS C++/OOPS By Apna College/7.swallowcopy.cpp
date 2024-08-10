#include <bits/stdc++.h>
using namespace std;

class student
{
public:
    string name;
    double *cgpaPtr;

    student(string name, double cgpa)
    {
        this->name = name;
        cgpaPtr=new double;
        *cgpaPtr=cgpa;
    }
    student(student &obj)
    {
        this->name = obj.name;
        this->cgpaPtr = obj.cgpaPtr;
    }
    void getInfo()
    {
        cout << name << endl;
        cout << *cgpaPtr << endl;
    }
};

int main()
{
    student s1{"Monjur", 3.42};
    student s2(s1);
    s1.getInfo();
    *(s2.cgpaPtr)=3.5;
    s1.getInfo();
}
