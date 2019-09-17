/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // eg: nums = 1, 2, 7, 4, 3, 1
        // ans = 1, 3, 1, 2, 4, 7
        // The method is to find the pivot where the array stops accending. In this case, the pivot is 2.
        // Find the smallest number that are greater than the pivot. Swap them.
        // Reverse the numbers starting from the ( pivot + 1 ) location to make them arrange in descending.
        int n = nums.size();
        int i = n - 2, j = n - 1;
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;
        if (i >= 0) {
            while (nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

