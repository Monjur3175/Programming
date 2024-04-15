#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class abstractEmployee{
    virtual void askforpromotion()=0;
};// This is like UI of Smartphone so the user don't have to worry about the implimentation of the code

class Employee:abstractEmployee
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
    void askforpromotion(){
        if (Age>=30)
        {
            cout<<Name<<" got Promoted !"<<endl;
        }
        else
        {
            cout<<Name<<", Sorry! No Promotion for you !!!"<<endl;
        }
        
    }
};
class developer:Employee{//child class
    public:
    string Favprogramminglang;
    developer(string name, string company, ll age,string favprogramminglang)
    :Employee(name,company,age)
    {Favprogramminglang=favprogramminglang;}
    void fixbug(){
        cout<<getname()<<" Fixed bug using "<<Favprogramminglang<<endl;
    }
};

int main()
{

    developer d=developer("Monjur","Xavier",39,"C++");

    return 0;
}
/*Here a child class inherits from the base/super/parent class which has it's own charactaristics*/