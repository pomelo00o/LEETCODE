/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int cnt = 0;
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int area = dfs(grid, visited, i, j);
                cnt = max(area, cnt);
            }
        }
        return cnt;
    }

    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || visited[r][c] == true || grid[r][c] == 0) return 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int area = 1;
        visited[r][c] = true;
        for (auto dir : directions) {
            int row = r + dir.first, col = c + dir.second;
            area += dfs(grid, visited, row, col);
        }
        return area;
    }
};

