/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int sum = 0;
        for (auto n : nums) {
            sum += n;
        }
        if (sum % 2 == 1) return false;
        int target = sum / 2; // transform into find_target_element task
        int idx = 0; // start from the largest element
        return helper(nums, target, idx);
    }

    bool helper(vector<int>& nums, int target, int idx) {
        if (idx >= nums.size()) return false;
        if (target == nums[idx]) return true;
        if (target < nums[idx]) return false;
        return helper(nums, target - nums[idx], idx + 1) || helper(nums, target, idx + 1);
    }
};

