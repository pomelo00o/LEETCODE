/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
class Solution {
private:
    int cnt = 0;

    void dfs(vector<string>& board, int r) {
        if (r == board.size()) {
            cnt ++;
            return;
        }
        for (int c = 0; c < board[0].size(); ++c) {
            if (isValid(board, r, c)) {
                board[r][c] = 'Q';
                dfs(board, r + 1);
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
        for (int row = r - 1, col = c + 1; row >= 0 && col < board.size(); --row, ++col) {
            if (board[row][col] == 'Q') return false;
        }
        return true;
    }
public:
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        dfs(board, 0);
        return cnt;
    }
};
// @lc code=end

