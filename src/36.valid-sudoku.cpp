/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> box(9, vector<bool>(9, false));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '1';
                if (row[i][num] || col[j][num] || box[i / 3 * 3 + j / 3][num]) return false;
                row[i][num] = col[j][num] = box[i / 3 * 3 + j / 3][num] = true;
            }
        }
        return true;
        // Tips: the main trick here is how to represent each box with i & j
        // with (i/3*3+j/3), we can map to the following graph
        // +---------+---------+---------+
        // | .  .  . | .  .  . | .  .  . |
        // | .  0  . | .  1  . | .  2  . |
        // | .  .  . | .  .  . | .  .  . |
        // +---------+---------+---------+
        // | .  .  . | .  .  . | .  .  . |
        // | .  3  . | .  4  . | .  5  . |
        // | .  .  . | .  .  . | .  .  . |
        // +---------+---------+---------+
        // | .  .  . | .  .  . | .  .  . |
        // | .  6  . | .  7  . | .  8  . |
        // | .  .  . | .  .  . | .  .  . |
        // +---------+---------+---------+
    }
};

