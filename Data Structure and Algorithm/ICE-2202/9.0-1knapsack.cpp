#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    int v[n + 1];
    int w[n + 1];

    cout << "Enter the values of items: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    cout << "Enter the weights of items: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }

    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (w[i] <= j)
            {
                dp[i][j] = max(v[i] + dp[i - 1][j - w[i]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << endl;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n--- Items Taken (0 = Not taken, 1 = Taken) ---\n";
    int x[n + 1] = {0};
    int i = n, j = W;

    while (i > 0 && j > 0)
    {
        if (dp[i][j] != dp[i - 1][j])
        {
            x[i] = 1;
            j -= w[i];
        }
        i--;
    }

    cout << "Item selection: ";
    for (int k = 1; k <= n; k++)
    {
        cout << x[k] << " ";
    }
    cout << endl;

    cout << "\nItems taken:\n";
    for (int k = 1; k <= n; k++)
    {
        if (x[k] == 1)
        {
            cout << "Item " << k << " (Weight: " << w[k] << ", Value: " << v[k] << ")\n";
        }
    }
    cout << "\nMaximum value in knapsack = " << dp[n][W] << endl;

    return 0;
}