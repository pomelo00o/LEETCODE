/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        int sz = candidates.size();
        vector<bool> visited(sz, false);
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        backtrack(combinations, candidates, curr, visited, target, 0);
        return combinations;
    }

    void backtrack(vector<vector<int>>& combinations, vector<int>& candidates, vector<int>& curr, vector<bool>& visited, int target, int start) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            combinations.push_back(curr);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (visited[i] == true) continue;
            if (i != 0 && candidates[i] == candidates[i - 1] && visited[i - 1] == false) continue;
            curr.push_back(candidates[i]);
            visited[i] = true;
            backtrack(combinations, candidates, curr, visited, target - candidates[i], i + 1);
            curr.pop_back();
            visited[i] = false;
        }
    }
};

