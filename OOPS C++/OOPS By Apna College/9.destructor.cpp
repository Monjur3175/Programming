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
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }
    ~student()
    {
        cout << "Hi! I delete All the memory" << endl;
        delete cgpaPtr;
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
    s1.getInfo();
    return 0;
}