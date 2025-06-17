#include <iostream>
#include <cmath>
using namespace std;

double f(double x) { return x * x - 4 * x - 10; }

int main()
{
    double a = -2, b = -1.5, c;
    while (fabs(b - a) > 0.0001)
    {
        c = (a + b) / 2;
        f(c) * f(a) < 0 ? b = c : a = c;
    }
    cout << "Root: " << c << endl;
    return 0;
}