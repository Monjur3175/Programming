#include <iostream>
using namespace std;

int n, t;
int a[20];
int x[20];

void print(int m) {
    cout << "{ ";
    for (int i = 0; i < m; i++) {
        cout << x[i] << " ";
    }
    cout << "}" << endl;
}

void solve(int i, int s, int k) {
    if (s == t) {
        print(k);
        return;
    }

    if (i == n || s > t) {
        return;
    }

    // Include a[i]
    x[k] = a[i];
    solve(i + 1, s + a[i], k + 1);

    // Exclude a[i]
    solve(i + 1, s, k);
}

int main() {
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements of the set: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Enter target sum: ";
    cin >> t;

    cout << "\nSubsets that sum to " << t << " are:\n";
    solve(0, 0, 0);

    return 0;
}