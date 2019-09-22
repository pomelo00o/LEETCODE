/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Friend Circles
 */
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int cnt = 0;
        int N = M.size();
        vector<bool> visited(N, false);
        for (int i = 0; i < N; ++i) {
            if (visited[i] == false) {
                dfs(M, visited, i);
                cnt ++;
            }
        }
        return cnt;
    }

    void dfs(vector<vector<int>>& M, vector<bool>& visited, int i) {
        visited[i] = true;
        for (int j = 0; j < M[0].size(); ++j) {
            if (M[i][j] == 0 || visited[j] == true) continue;
            dfs(M, visited, j);
        }
    }
};

