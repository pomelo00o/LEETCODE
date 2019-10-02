/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution {
private:
    bool dfs(vector<vector<char>>& board, int i, int j) {
        if (i == 9) return true;
        if (j == 9) return dfs(board, i + 1, 0);
        if (board[i][j] != '.') return dfs(board, i, j + 1);
        for (int num = 1; num < 10; ++num) {
            if (!isValid(board, i, j, num)) continue;
            board[i][j] = num + '0';
            if (dfs(board, i, j + 1) == true) return true;
            board[i][j] = '.';
        }   
        return false;
    }

    bool isValid(vector<vector<char>>& board, int r, int c, int v) {
        for (int col = 0; col < 9; ++col) {
            if (board[r][col] - '0' == v) return false;
        }
        for (int row = 0; row < 9; ++row) {
            if (board[row][c] - '0' == v) return false;
        }
        for (int row = r / 3 * 3; row < r / 3 * 3 + 3; ++row) {
            for (int col = c / 3 * 3; col < c / 3 * 3 + 3; ++col) {
                if (board[row][col] - '0' == v) return false;
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0, 0);
        return;
    }
};
// @lc code=end

