#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> A = {1,2,3,4};
    cout << "R1: ";
    for (int a : A)
        for (int b : A)
            if (b % a == 0) cout << "(" << a << "," << b << ") ";
    cout << "\nR2: ";
    for (int a : A)
        for (int b : A)
            if (a <= b) cout << "(" << a << "," << b << ") ";
    return 0;
}