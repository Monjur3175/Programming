#include<iostream>
#include<string>
using namespace std;

class monjur{
    private:
    string name;
    int age;
    public:
    monjur(string n,int a):name(n),age(a){
        cout<<"I am a Constructor"<<endl;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};
int main()
{
    monjur m("Nishan",20);
    m.display();
    return 0;
}
