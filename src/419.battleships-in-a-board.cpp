/*
 * @lc app=leetcode id=419 lang=cpp
 *
 * [419] Battleships in a Board
 */
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return 0;
        int res = 0, m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> dirs;
        dirs.push_back(make_pair(0, 1));
        dirs.push_back(make_pair(0, -1));
        dirs.push_back(make_pair(1, 0));
        dirs.push_back(make_pair(-1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'X' && !visited[i][j]) {
                    res += 1;
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    while (!q.empty()) {
                        auto curr = q.front();
                        q.pop();
                        visited[curr.first][curr.second] = true;
                        for (auto dir : dirs) {
                            int x = curr.first + dir.first;
                            int y = curr.second + dir.second;
                            if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || board[x][y] == '.') continue;
                            q.push({x, y});
                        }
                    }
                }
            }
        }
        return res;
    }
};

