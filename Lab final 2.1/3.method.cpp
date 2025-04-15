#include <iostream>
using namespace std;
class Area {
public:
    int calculate(int length, int width) {
        cout<<"I am 1st Method"<<endl;
    }
    int calculate(int side) {
        cout<<"I am 2nd Method"<<endl;
    }
};
int main() {
    Area a;
    int x,y;
    cin>>x>>y;
    cout << "Area (rect): " << a.calculate(x,y) << endl;
    return 0;
}
