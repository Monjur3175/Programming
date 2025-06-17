#include <iostream>
using namespace std;

int main()
{
    int MR1[3][3] = {{1, 0, 1}, {1, 0, 0}, {0, 1, 0}};
    int MR2[3][3] = {{1, 0, 1}, {0, 1, 1}, {1, 0, 0}};
    cout << "Union:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << (MR1[i][j] || MR2[i][j]) << " ";
        cout << endl;
    }
    cout << "Intersection:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << (MR1[i][j] && MR2[i][j]) << " ";
        cout << endl;
    }
    return 0;
}