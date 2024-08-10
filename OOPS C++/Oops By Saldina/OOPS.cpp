#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Employee
{
public://access modifier(public,Private,Protected,Default Private)
    string Name;
    string Company;
    ll Age;
    void introduceyourself()//Function
    {
        cout << "NAME- " << Name << endl;
        cout << "Company- " << Company << endl;
        cout << "Age- " << Age << endl;
    }
    Employee(string name, string company, ll age)//Constructor(user derfined)
    {
        Name = name;
        Company = company;
        Age = age;
    }
};

int main()
{
    Employee Employee1 = Employee("Monjur", "Student", 23);//Using Contructor Technique
    // Employee1.Name="Monjur";//Using Default Constructor Technique
    // Employee1.Company="Student";
    // Employee1.Age=23;
    Employee1.introduceyourself();//Calling the function(from Class)in the Main Function

    Employee Employee2 = Employee("Morshed", "Cuber", 25);
    // Employee2.Name="Morshed";
    // Employee2.Company="Cuber";
    // Employee2.Age=25;
    Employee2.introduceyourself();

    return 0;
}