#include <iostream>
using namespace std;

int main()
{
    double x[] = {5, 6, 9, 11};
    double y[] = {12, 13, 14, 16};
    double xi = 10, res = 0;
    for (int i = 0; i < 4; i++)
    {
        double term = y[i];
        for (int j = 0; j < 4; j++)
            if (j != i)
                term *= (xi - x[j]) / (x[i] - x[j]);
        res += term;
    }
    cout << "y(10) = " << res << endl;
    return 0;
}