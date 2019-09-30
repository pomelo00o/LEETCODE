/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j] == false && grid[i][j] == '1') {
                    dfs(grid, visited, i, j);
                    cnt ++;
                }
            }
        }
        return cnt;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || visited[r][c] == true || grid[r][c] == '0') {
            return;
        }
        visited[r][c] = true;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto dir : directions) {
            int row = r + dir.first, col = c + dir.second;
            dfs(grid, visited, row, col);
        }
    }
};

