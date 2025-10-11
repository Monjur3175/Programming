#include <bits/stdc++.h>
using namespace std;
void printboard(vector<string> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << board[i] << endl;
    }

    cout << endl;
}
bool issafe(int row, int col, int n, vector<string> &board)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}
void solve(vector<string> &board, int row, int n)
{
    if (row == n)
    {
        cout << "final solution :" << endl;
        printboard(board, n);
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (issafe(row, col, n, board))
        {
            board[row][col] = 'Q';
            cout << "place q at row " << row + 1 << ", col " << col + 1 << "\n";
            printboard(board, n);
            solve(board, row + 1, n);
            board[row][col] = '.';
            cout << "backtrack from now " << row + 1 << " , col" << col + 1 << ":\n";
            printboard(board, n);
        }
    }
}
int main()
{
    int n;
    cout << "enter the n queens :";
    cin >> n;
    vector<string> board(n, string(n, '.'));

    cout << "solution for  " << n << "queen problems :";
    solve(board, 0, n);
}