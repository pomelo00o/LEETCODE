/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return;
        int i = n - 2, j = n - 1;
        while (i >= 0 && nums[i] >= nums[i + 1]) i -= 1;
        int pivot = nums[i];
        if (i >= 0) {
            while (nums[j] <= nums[i]) j -= 1;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

