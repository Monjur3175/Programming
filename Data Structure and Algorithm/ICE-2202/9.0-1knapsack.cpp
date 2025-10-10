#include <iostream>
using namespace std;

// Function to find the maximum of two numbers
int maxValue(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int n, W;  // n = number of items, W = capacity of knapsack

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    int value[n + 1];
    int weight[n + 1];

    cout << "Enter the values of items: ";
    for (int i = 1; i <= n; i++) {
        cin >> value[i];
    }

    cout << "Enter the weights of items: ";
    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
    }

    int dp[n + 1][W + 1];

    // Initialize DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = 0;
        }
    }

    // Fill DP table using 0/1 Knapsack formula
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weight[i] <= w) {
                dp[i][w] = maxValue(value[i] + dp[i - 1][w - weight[i]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "\nMaximum value in knapsack = " << dp[n][W] << endl;

    return 0;
}
