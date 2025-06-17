#include <iostream>
#include <cmath>
using namespace std;

double f(double x) { return x * x - x - 2; }

int main()
{
    double a = 1, b = 3, c;
    while (fabs(b - a) > 0.0001)
    {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        f(c) * f(a) < 0 ? b = c : a = c;
    }
    cout << "Root: " << c << endl;
    return 0;
}