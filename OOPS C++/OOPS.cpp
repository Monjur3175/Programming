#include <iostream>
using std::string;
using namespace std;
typedef long long ll;

class Employee
{
public:
    string Name;
    string Company;
    int Age;
    void introduceyourself()
    {
        cout << "NAME- " << Name << endl;
        cout << "Company- " << Company << endl;
        cout << "Age- " << Age << endl;
    }
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }
};

int main()
{
    Employee Employee1 = Employee("Monjur", "Student", 23);
    // Employee1.Name="Monjur";
    // Employee1.Company="Student";
    // Employee1.Age=23;
    Employee1.introduceyourself();

    Employee Employee2 = Employee("Morshed", "Cuber", 25);
    // Employee2.Name="Morshed";
    // Employee2.Company="Cuber";
    // Employee2.Age=25;
    Employee2.introduceyourself();

    return 0;
}