/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 1) return nums[0];
        vector<int> dp(sz, INT_MIN);
        dp[0] = nums[0];
        int maxSum = dp[0];
        for (int i = 1; i < sz; ++i) {
            if (dp[i - 1] > 0) {
                dp[i] = dp[i - 1] + nums[i];
            } else {
                dp[i] = nums[i];
            }
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }
};

