/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (search(board, word, 0, i, j, visited)) return true;
            }
        }
        return false;
    }

    bool search(vector<vector<char>>& board, string word, int idx, int x, int y, vector<vector<bool>>& visited) {
        if (idx == word.size()) return true;
        int m = board.size(), n = board[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || board[x][y] != word[idx]) return false;
        visited[x][y] = true;
        idx += 1;
        bool res = false;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto dir : dirs) {
            res = res || search(board, word, idx, x + dir[0], y + dir[1], visited);
        }
        visited[x][y] = false;
        return res;
    }
};

