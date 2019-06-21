/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> vec;
        int start = 0;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, start, vec, res);
        return res;
    }

    void helper(vector<int> candidates, int target, int start, vector<int>& vec, vector<vector<int>>& res) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(vec);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            int curr = candidates[i];
            vec.push_back(curr);
            helper(candidates, target - curr, i + 1, vec, res);
            vec.pop_back();
        }
    }
};

