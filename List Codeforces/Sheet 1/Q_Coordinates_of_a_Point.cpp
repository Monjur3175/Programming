#include <iostream>
using namespace std;

int main() {
    // Input variables
    double X, Y;

    // Read input
    cin >> X >> Y;

    // Check the quarter or axis
    if (X == 0 && Y == 0) {
        cout << "Origem" << endl;
    } else if (X == 0) {
        cout << "Eixo Y" << endl;
    } else if (Y == 0) {
        cout << "Eixo X" << endl;
    } else {
        // Determine the quarter
        if (X > 0 && Y > 0) {
            cout << "Q1" << endl;
        } else if (X < 0 && Y > 0) {
            cout << "Q2" << endl;
        } else if (X < 0 && Y < 0) {
            cout << "Q3" << endl;
        } else {
            cout << "Q4" << endl;
        }
    }

    return 0;
}
