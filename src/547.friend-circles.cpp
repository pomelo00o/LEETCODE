/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Friend Circles
 */
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int res = 0;
        vector<bool> visited(M.size(), false);
        for (int i = 0; i < M.size(); ++i) {
            if (visited[i]) continue;
            helper(M, visited, i);
            res += 1;
        }
        return res;
    }

    void helper(vector<vector<int>>& M, vector<bool>& visited, int k) {
        visited[k] = true;
        for (int i = 0; i < M.size(); ++i) {
            if (M[k][i] == 0 || visited[i]) continue;
            helper(M, visited, i);
        }
    }
};

