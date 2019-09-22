/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        vector<int> curr;
        helper(candidates, target, 0, combinations, curr);
        return combinations;
    }

    void helper(vector<int>& candidates, int target, int start, vector<vector<int>>& combinations, vector<int>& curr) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            combinations.push_back(curr);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            curr.push_back(candidates[i]);
            helper(candidates, target - candidates[i], i, combinations, curr);
            curr.pop_back();
        }
    }
};

