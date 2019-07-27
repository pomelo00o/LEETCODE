/*
 * @lc app=leetcode id=778 lang=cpp
 *
 * [778] Swim in Rising Water
 */
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = grid[0][0], right = pow(n, 2);
        while (left < right) {
            int mid = (left + right) / 2;
            if (!helper(grid, mid)) left = mid + 1;
            else right = mid;
        }
        return left;
    }

    bool helper(vector<vector<int>>& grid, int mid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false)); // mark the first point as visited
        auto left = make_pair(1, 0);
        auto right = make_pair(-1, 0);
        auto up = make_pair(0, 1);
        auto down = make_pair(0, -1);
        vector<pair<int, int>> dirs{left, right, up, down};
        stack<pair<int, int>> stk{{make_pair(0, 0)}}; // push the first point into stack
        while (!stk.empty()) {
            auto tmp = stk.top();
            stk.pop();
            int i = tmp.first, j = tmp.second;
            if (i == n - 1 && j == n - 1) return true;
            for (auto dir : dirs) {
                int x = i + dir.first, y = j + dir.second;
                if (x < 0 || x >= n || y < 0 || y >= n || visited[x][y] || grid[x][y] > mid) continue;
                stk.push(make_pair(x, y));
                visited[x][y] = true;
            }
        }
        return false;
    }
};

