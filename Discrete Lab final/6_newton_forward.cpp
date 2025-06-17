#include <iostream>
using namespace std;

int main()
{
    int x[] = {1911, 1921, 1931, 1941, 1951, 1961};
    int y[] = {12, 15, 20, 27, 39, 52};
    double u = (1946 - x[3]) / 10.0;
    double diff[6][6];
    for (int i = 0; i < 6; i++)
        diff[i][0] = y[i];
    for (int j = 1; j < 6; j++)
        for (int i = 0; i < 6 - j; i++)
            diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
    double res = y[3] + u * (diff[3][1] + (u - 1) * (diff[3][2] / 2 + (u - 2) * (diff[3][3] / 6 + (u - 3) * (diff[3][4] / 24))));
    cout << "Population in 1946: " << res << endl;
    return 0;
}