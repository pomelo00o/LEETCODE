/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
private:
    void dfs(vector<string>& board, int r, vector<vector<string>>& sol) {
        if (r == board.size()) {
            sol.push_back(board);
            return;
        }
        for (int c = 0; c < board[0].size(); ++c) {
            if (isValid(board, r, c)) {
                board[r][c] = 'Q';
                dfs(board, r + 1, sol);
                board[r][c] = '.';
            }
        }
    }

    bool isValid(vector<string>& board, int r, int c) {
        for (int col = 0; col < board[0].size(); ++col) {
            if (board[r][col] == 'Q') return false;
        }
        for (int row = 0; row < board.size(); ++row) {
            if (board[row][c] == 'Q') return false;
        }
        for (int row = r - 1, col = c - 1; row >= 0 && col >= 0; --row, --col) {
            if (board[row][col] == 'Q') return false;
        }
        for (int row = r - 1, col = c + 1; row >= 0 && col < board[0].size(); --row, ++col) {
            if (board[row][col] == 'Q') return false;
        }
        return true;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> sol;
        vector<string> board(n, string(n, '.'));
        dfs(board, 0, sol);
        return sol;
    }
};
// @lc code=end

