#include <bits/stdc++.h>
using namespace std;

void solve(int n, int r, vector<int> &col, vector<int> &d1, vector<int> &d2,
           vector<int> &place, vector<vector<string>> &sols)
{
    if (r == n)
    {
        vector<string> board(n, string(n, '.'));
        for (int i = 0; i < n; i++)
            board[i][place[i]] = 'Q';
        sols.push_back(board);
        return;
    }
    for (int c = 0; c < n; c++)
    {
        if (!col[c] && !d1[r - c + n - 1] && !d2[r + c])
        {
            col[c] = d1[r - c + n - 1] = d2[r + c] = 1;
            place[r] = c;
            solve(n, r + 1, col, d1, d2, place, sols);
            col[c] = d1[r - c + n - 1] = d2[r + c] = 0;
        }
    }
}

int main()
{
    int n = 4;
    vector<int> col(n), d1(2 * n - 1), d2(2 * n - 1), place(n);
    vector<vector<string>> sols;
    solve(n, 0, col, d1, d2, place, sols);
    int id = 1;
    for (auto &b : sols)
    {
        cout << "Solution " << id++ << ":\n";
        for (auto &row : b)
            cout << row << '\n';
        cout << '\n';
    }
    cout << "Total solutions: " << sols.size() << '\n';
}
