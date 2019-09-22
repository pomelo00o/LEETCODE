/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> permutations;
        int sz = nums.size();
        vector<bool> visited(sz, false);
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtrack(nums, permutations, curr, visited);
        return permutations;
    }

    void backtrack(vector<int>& nums, vector<vector<int>>& permutations, vector<int>& curr, vector<bool>& visited) {
        if (curr.size() == nums.size()) {
            permutations.push_back(curr);
        } else {
            for (int i = 0; i < nums.size(); ++i) {
                if (i != 0 && nums[i] == nums[i - 1] && visited[i - 1] == false) {
                    continue;
                }
                if (visited[i] == true) continue;
                curr.push_back(nums[i]);
                visited[i] = true;
                backtrack(nums, permutations, curr, visited);
                curr.pop_back();
                visited[i] = false;
            }
        }
    }
};

