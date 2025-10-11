#include <iostream>
using namespace std;

#define N 4 // You can change N to any number (like 5, 6, 8 etc.)

// Function to print the chessboard
void printBoard(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 1)
            {
                cout << "Q "; // Q means Queen
            }
            else
            {
                cout << ". "; // . means empty space
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if a queen can be placed safely
bool isSafe(int board[N][N], int row, int col)
{
    // Check column above
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    return true; // Safe position
}

// Function to solve the N-Queens problem using recursion
bool solveNQueens(int board[N][N], int row)
{
    // Base condition: If all queens are placed
    if (row == N)
    {
        printBoard(board);
        return true;
    }

    bool foundSolution = false;

    // Try placing queen in each column of this row
    for (int col = 0; col < N; col++)
    {
        if (isSafe(board, row, col))
        {
            // Place queen
            board[row][col] = 1;

            // Recurse for next row
            foundSolution = solveNQueens(board, row + 1) || foundSolution;

            // Backtrack: Remove queen
            board[row][col] = 0;
        }
    }

    return foundSolution;
}

// Main function
int main()
{
    int board[N][N]; // Initialize board with 0 (empty)

    cout << "All possible solutions for " << N << "-Queens Problem:\n\n";
    bool result = solveNQueens(board, 0);

    if (!result)
    {
        cout << "No solution exists!" << endl;
    }

    return 0;
}
