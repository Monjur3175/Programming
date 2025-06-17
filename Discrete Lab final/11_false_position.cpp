#include <iostream>
#include <cmath>
using namespace std;

double f(double x) { return x*x - x - 2; }

int main() {
    double a = 1.0, b = 3.0, c;
    const double epsilon = 1e-6; 

    do {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        if (f(c) * f(a) < 0) 
            b = c;
        else 
            a = c;
    } while (abs(f(c)) > epsilon);

    cout << "Root: " << c << endl;
    return 0;
}