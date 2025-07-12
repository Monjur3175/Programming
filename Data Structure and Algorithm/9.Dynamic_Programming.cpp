#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// 1. Fibonacci Series (Top-Down with memoization)
int fibMemoHelper(int n, vector<int> &memo)
{
    if (n <= 1)
        return n;
    if (memo[n] != -1)
        return memo[n];
    memo[n] = fibMemoHelper(n - 1, memo) + fibMemoHelper(n - 2, memo);
    return memo[n];
}

int fibonacci(int n)
{
    vector<int> memo(n + 1, -1);
    return fibMemoHelper(n, memo);
}

// 2. 0/1 Knapsack (Bottom-Up)
int knapsack(int W, vector<int> &wt, vector<int> &val)
{
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (wt[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

// 3. Longest Common Subsequence (LCS)
int lcs(string &X, string &Y)
{
    int m = X.size(), n = Y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

// 4. Longest Increasing Subsequence (LIS)
int lis(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 1);
    int maxLen = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}

// 5. Matrix Chain Multiplication
int matrixChainOrder(vector<int> &dims)
{
    int n = dims.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int l = 2; l <= n; l++)
    {
        for (int i = 0; i < n - l + 1; i++)
        {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[0][n - 1];
}

// 6. Coin Change (Number of ways)
int coinChangeWays(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int coin : coins)
    {
        for (int x = coin; x <= amount; x++)
        {
            dp[x] += dp[x - coin];
        }
    }
    return dp[amount];
}
//-----------------------------
// Travelling Salesman Problem
//-----------------------------
// Using DP + bitmasking (Held-Karp algorithm)
int tsp(int pos, int mask, const vector<vector<int>> &dist, vector<vector<int>> &dp)
{
    int n = dist.size();
    if (mask == (1 << n) - 1)
    {
        return dist[pos][0]; // Return to start
    }
    if (dp[pos][mask] != -1)
        return dp[pos][mask];
    int ans = INT_MAX;
    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            int newAns = dist[pos][city] + tsp(city, mask | (1 << city), dist, dp);
            ans = min(ans, newAns);
        }
    }
    return dp[pos][mask] = ans;
}

//-----------------------------
// Edit Distance (Levenshtein)
//-----------------------------
int editDistance(const string &s1, const string &s2)
{
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    for (int j = 0; j <= n; j++)
        dp[0][j] = j;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {
                dp[i][j] = 1 + min({
                                   dp[i - 1][j],    // delete
                                   dp[i][j - 1],    // insert
                                   dp[i - 1][j - 1] // replace
                               });
            }
        }
    }
    return dp[m][n];
}
//-----------------------------------
// Demo Runner
//-----------------------------------
int main()
{
    // Fibonacci
    int n = 10;
    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << "\n";

    // 0/1 Knapsack
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int W = 7;
    cout << "Knapsack max value = " << knapsack(W, wt, val) << "\n";

    // LCS
    string X = "AGGTAB", Y = "GXTXAYB";
    cout << "LCS length = " << lcs(X, Y) << "\n";

    // LIS
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
    cout << "LIS length = " << lis(arr) << "\n";

    // Matrix Chain Multiplication
    vector<int> dims = {40, 20, 30, 10, 30};
    cout << "Minimum multiplication cost = " << matrixChainOrder(dims) << "\n";

    // Coin Change
    vector<int> coins = {1, 2, 3};
    int amount = 4;
    cout << "Number of ways to make change = " << coinChangeWays(coins, amount) << "\n";
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};
    int n = dist.size();
    vector<vector<int>> dp(n, vector<int>(1 << n, -1));
    int tspResult = tsp(0, 1, dist, dp);
    cout << "Minimum cost of TSP: " << tspResult << "\n";

    // Edit Distance Demo
    string s1 = "kitten";
    string s2 = "sitting";
    cout << "Edit Distance between '" << s1 << "' and '" << s2 << "' is: " << editDistance(s1, s2) << "\n";
    return 0;
}
