#include <iostream>
using namespace std;

int main()
{
    int x[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int y[] = {1, 8, 27, 64, 125, 216, 343, 512};
    double u = (7.5 - 8) / 1.0;
    double diff[8][8];
    for (int i = 0; i < 8; i++)
        diff[i][0] = y[i];
    for (int j = 1; j < 8; j++)
        for (int i = 7; i >= j; i--)
            diff[i][j] = diff[i][j - 1] - diff[i - 1][j - 1];
    double res = y[7] + u * (diff[7][1] + (u + 1) * (diff[7][2] / 2 + (u + 2) * (diff[7][3] / 6)));
    cout << "f(7.5) = " << res << endl;
    return 0;
}