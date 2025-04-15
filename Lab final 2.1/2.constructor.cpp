#include <iostream>
using namespace std;
class Student {
    string name;
    int age;
public:
    Student(string n, int a) : name(n), age(a) {
        cout<<"I am a constructor"<<endl;
    }
    void display() {
        cout << "Name: " << name << ", Age: " << age;
    }
};
int main() {
    Student s("Saikat", 40);
    s.display();
    return 0;
}
