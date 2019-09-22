/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */
class Solution {
public:
    int numSquares(int n) {
        vector<bool> visited(n + 1, false);
        queue<pair<int, int>> q;
        q.push(make_pair(n, 0));
        visited[n] = true;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int num = p.first, level = p.second;
            for (int i = 1; i * i <= num; ++i) {
                int diff = num - i * i;
                if (diff < 0) break;
                else if (diff == 0) return level + 1;
                else {
                    if (visited[diff] == false) {
                        q.push(make_pair(diff, level + 1));
                        visited[diff] = true;
                    }
                }
            }
        }
        return n;
    }
};

