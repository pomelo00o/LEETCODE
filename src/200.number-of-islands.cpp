/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '0' || visited[i][j]) continue;
                else helper(grid, visited, i, j);
                res += 1;
            }
        }
        return res;
    }

    void helper(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || visited[x][y] || grid[x][y] == '0') return;
        visited[x][y] = true;
        helper(grid, visited, x + 1, y);
        helper(grid, visited, x - 1, y);
        helper(grid, visited, x, y + 1);
        helper(grid, visited, x, y - 1);
    }
};

