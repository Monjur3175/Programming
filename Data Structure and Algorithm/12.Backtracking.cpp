#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//---------------------------
// 1. N-Queens Problem
bool isSafeNQueens(const vector<int>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        int c = board[i];
        if (c == col || abs(c - col) == abs(i - row)) return false;
    }
    return true;
}

void solveNQueensHelper(int n, int row, vector<int>& board, vector<vector<int>>& solutions) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafeNQueens(board, row, col)) {
            board[row] = col;
            solveNQueensHelper(n, row + 1, board, solutions);
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> solutions;
    vector<int> board(n, -1);
    solveNQueensHelper(n, 0, board, solutions);
    return solutions;
}

//---------------------------
// 2. Sudoku Solver
bool isSafeSudoku(vector<vector<int>>& board, int row, int col, int num) {
    for (int x = 0; x < 9; x++) {
        if (board[row][x] == num || board[x][col] == num) return false;
    }
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[startRow + i][startCol + j] == num) return false;
    return true;
}

bool solveSudoku(vector<vector<int>>& board, int row = 0, int col = 0) {
    if (row == 9) return true;
    if (col == 9) return solveSudoku(board, row + 1, 0);
    if (board[row][col] != 0) return solveSudoku(board, row, col + 1);

    for (int num = 1; num <= 9; num++) {
        if (isSafeSudoku(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board, row, col + 1)) return true;
            board[row][col] = 0; // backtrack
        }
    }
    return false;
}

//---------------------------
// 3. Subset Generation (Power Set)
void subsetHelper(const vector<int>& nums, int idx, vector<int>& current, vector<vector<int>>& subsets) {
    if (idx == nums.size()) {
        subsets.push_back(current);
        return;
    }
    // exclude
    subsetHelper(nums, idx + 1, current, subsets);

    // include
    current.push_back(nums[idx]);
    subsetHelper(nums, idx + 1, current, subsets);
    current.pop_back();
}

vector<vector<int>> subsets(const vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> current;
    subsetHelper(nums, 0, current, res);
    return res;
}

//---------------------------
// 4. Permutations
void permuteHelper(vector<int>& nums, int start, vector<vector<int>>& result) {
    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        permuteHelper(nums, start + 1, result);
        swap(nums[start], nums[i]);
    }
}

vector<vector<int>> permutations(vector<int> nums) {
    vector<vector<int>> result;
    permuteHelper(nums, 0, result);
    return result;
}

//---------------------------
// Demo main
int main() {
    // N-Queens
    int n = 4;
    auto queens = solveNQueens(n);
    cout << "N-Queens solutions count for " << n << ": " << queens.size() << "\n";
    for (auto& sol : queens) {
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) cout << (sol[r] == c ? "Q " : ". ");
            cout << "\n";
        }
        cout << "\n";
    }

    // Sudoku Solver
    vector<vector<int>> sudoku = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    if (solveSudoku(sudoku)) {
        cout << "Sudoku solved:\n";
        for (auto& row : sudoku) {
            for (int val : row) cout << val << " ";
            cout << "\n";
        }
    } else {
        cout << "No solution for Sudoku\n";
    }

    // Subset generation
    vector<int> nums = {1, 2, 3};
    auto subs = subsets(nums);
    cout << "Subsets:\n";
    for (auto& s : subs) {
        cout << "{ ";
        for (int v : s) cout << v << " ";
        cout << "}\n";
    }

    // Permutations
    auto perms = permutations(nums);
    cout << "Permutations:\n";
    for (auto& p : perms) {
        for (int v : p) cout << v << " ";
        cout << "\n";
    }

    return 0;
}
