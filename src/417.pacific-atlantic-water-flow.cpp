/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> paths;
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) {
                    dfs(matrix, pacific, i, j);
                }
                if (i == m - 1 || j == n - 1) {
                    dfs(matrix, atlantic, i, j);
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] == true && atlantic[i][j] == true) {
                    paths.push_back({i, j});
                }
            }
        }
        return paths;
    }

    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& ocean, int r, int c) {
        if (ocean[r][c] == true) return;
        ocean[r][c] = true;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto dir : directions) {
            int row = r + dir.first, col = c + dir.second;
            if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size() || matrix[r][c] > matrix[row][col]) continue;
            dfs(matrix, ocean, row, col);
        }
    }
};

