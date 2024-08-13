#include <bits/stdc++.h>
using namespace std;

class shape{//Abstruct Class
    virtual void draw()=0;//pure virtual function
};
class circle:public shape{
    public:
    void draw(){
        cout<<"Drawing a Circle"<<endl;
    }
};

int main()
{
    circle c1;
    c1.draw();
}
