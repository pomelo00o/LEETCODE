class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        unordered_set<string> uset;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && visited[i][j] == false) {
                    string str;
                    dfs(grid, visited, i, j, str, 'o');
                    uset.insert(str);
                }
            }
        }
        return uset.size();
    }

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c, string& str, char ch) {
        int m = grid.size(), n = grid[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] == true || grid[r][c] != 1) {
            str.push_back('f');
            return;
        }
        visited[r][c] = true;
        str.push_back(ch);
        dfs(grid, visited, r + 1, c, str, 'd');
        dfs(grid, visited, r - 1, c, str, 'u');
        dfs(grid, visited, r, c + 1, str, 'r');
        dfs(grid, visited, r, c - 1, str, 'l');
    }
};