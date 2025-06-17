#include <iostream>
using namespace std;

int main() {
    int A[] = {1,2,3}, B[] = {1,2};
    int matrix[3][2] = {0};
    cout << "Pairs: ";
    for (int a : A)
        for (int b : B)
            if (a > b) {
                cout << "(" << a << "," << b << ") ";
                matrix[a-1][b-1] = 1;
            }
    cout << "\nMatrix:\n";
    for (int i=0; i<3; i++) {
        for (int j=0; j<2; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}