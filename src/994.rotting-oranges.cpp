/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res = 0;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int fresh_cnt = 0;
        queue<vector<int>> rotten;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) fresh_cnt ++;
                else if (grid[i][j] == 2) rotten.push({i, j});
            }
        }
        while (!rotten.empty()) {
            int sz = rotten.size();
            for (int i = 0; i < sz; ++i) {
                auto loc = rotten.front();
                rotten.pop();
                int r = loc[0], c = loc[1];
                for (auto dir : dirs) {
                    int x = r + dir[0], y = c + dir[1];
                    if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        fresh_cnt --;
                        rotten.push({x, y});
                    }
                }
            }
            if (rotten.size()) res ++;
        }
        if (fresh_cnt) return -1;
        return res;
    }
};

