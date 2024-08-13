#include <bits/stdc++.h>
using namespace std;

class print{
    public:
    //function overloading
    void show(int x){
        cout<<x<<endl;
    }
    void show(char ch){
        cout<<ch<<endl;
    }
};

int main()
{
    print p1;
    p1.show('%');
}