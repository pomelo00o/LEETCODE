/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        int start = 0;
        vector<int> vec;
        helper(candidates, target, start, vec, res);
        return res;
    }

    void helper(vector<int>& candidates, int target, int start, vector<int>& vec, vector<vector<int>>& res) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            res.push_back(vec);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            int curr = candidates[i];
            vec.push_back(curr);
            helper(candidates, target - curr, i, vec, res);
            vec.pop_back();
        }
    }
};

