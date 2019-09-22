/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        int sz = nums.size();
        vector<bool> visited(sz, false);
        vector<int> curr;
        backtrack(nums, permutations, curr, visited);
        return permutations;
    }

    void backtrack(vector<int>& nums, vector<vector<int>>& permutations, vector<int>& curr, vector<bool>& visited) {
        if (curr.size() == nums.size()) permutations.push_back(curr);
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i] == true) continue;
            curr.push_back(nums[i]);
            visited[i] = true;
            backtrack(nums, permutations, curr, visited);
            curr.pop_back();
            visited[i] = false;
        }
    }
};

