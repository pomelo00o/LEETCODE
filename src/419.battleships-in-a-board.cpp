/*
 * @lc app=leetcode id=419 lang=cpp
 *
 * [419] Battleships in a Board
 */
class Solution {
private:
    bool checkUpLeft(vector<vector<char>>& board, int r, int c) {
        if (r > 0 && board[r - 1][c] == 'X') return false;
        if (c > 0 && board[r][c - 1] == 'X') return false;
        return true;
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return 0;
        int m = board.size(), n = board[0].size();
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'X' && checkUpLeft(board, i, j) == true) {
                    cnt ++;
                }
            }
        }
        return cnt;
    }
};

