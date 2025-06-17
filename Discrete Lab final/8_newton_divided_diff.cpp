#include <iostream>
using namespace std;

int main()
{
    double x[] = {4, 5, 7, 10, 11, 13};
    double y[] = {48, 100, 294, 900, 1210, 2028};
    double diff[6][6];
    int n = 6;
    for (int i = 0; i < n; i++)
        diff[i][0] = y[i];
    for (int j = 1; j < n; j++)
        for (int i = 0; i < n - j; i++)
            diff[i][j] = (diff[i + 1][j - 1] - diff[i][j - 1]) / (x[i + j] - x[i]);
    double res = diff[0][0];
    double term = 1.0;
    for (int j = 1; j < n; j++)
    {
        term *= (15 - x[j - 1]);
        res += term * diff[0][j];
    }
    cout << "f(15) = " << res << endl;
    return 0;
}