/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        int maxSum = 0;
        int sz = nums.size();
        if (sz == 0) return 0;
        if (sz == 1) return nums[0];
        if (sz == 2) return max(nums[0], nums[1]);
        vector<int> dp(sz, INT_MIN);
        dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < sz; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }
};

