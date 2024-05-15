#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int arr[N][N];

void func(){//second [value] must be passed here in 2D array
    arr[0][0]=5;
}

int main() {
    
    arr[0][0]=7;
    cout<<arr[0][0]<<endl;
    func();
    cout<<arr[0][0]<<endl;
return 0;
}
//in Competitive programming you should declear global variable