/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if  (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
        if (n == 1) return 1;
        queue<pair<int, int>> q;
        vector<vector<int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        q.push(make_pair(0, 0));
        grid[0][0] = 1;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (auto dir : dirs) {
                int x = p.first + dir[0], y = p.second + dir[1];
                if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 0) {
                    grid[x][y] = grid[p.first][p.second] + 1;
                    q.push(make_pair(x, y));
                    if (x == n - 1 && y == n - 1) return grid[x][y];
                }
            }
        }
        return -1;
    }
};

