#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Employee
{
    private:
    string Name;
    string Company;
    ll Age;
    /*if this data in private access modifier needed to be accessed from outside the class
    we have to use this getters and setters in public access modifiers*/
    public:    
    void setname(string name){//setter
        Name=name;
    }
    string getname(){//getter
        return Name;
    }
    void setcompany(string company){//setter
        Company=company;
    }
    string getcompany(){//getter
        return Company;
    }
    void setage(ll age){//setter
        if (age>=18)
        {
            Age=age;
        }
    }
    ll getage(){//getter
        return Age;
    }
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
    Employee1.setage(15);//it will not be taken as a input
    cout<<Employee1.getname()<<" is "<<Employee1.getage()<<" years old"<<endl;

    return 0;
}