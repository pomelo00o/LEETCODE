/*
 * @lc app=leetcode id=529 lang=cpp
 *
 * [529] Minesweeper
 */
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board.empty() || board[0].empty()) return board;
        int m = board.size(), n = board[0].size();
        int r = click[0], c = click[1];
        int cnt = 0;
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
        } else {
            vector<vector<int>> neighbors;
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    int x = r + i, y = c + j;
                    if (x < 0 || x >= m || y < 0 || y >= n) {
                        continue;
                    } else if (board[x][y] == 'M') {
                        cnt++;
                    } else if (board[x][y] == 'E' && cnt == 0) { 
                        neighbors.push_back({x, y});
                    }
                }
            }
            if (cnt > 0) {
                board[r][c] = cnt + '0';
            } else {
                for (auto neighbor : neighbors) {
                    board[neighbor[0]][neighbor[1]] = 'B';
                    updateBoard(board, neighbor);
                }
            }
        }
        return board;
    }
};

