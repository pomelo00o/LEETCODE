/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */
class Solution {
public:
    int trap(vector<int>& height) {
        // dp: traverse 2 times
        // create a one-dimension dp[]
        // first traverse: dp[i] stores the greatest number on the left side of i
        // second traverse: dp[i] stores the greatest number on the right side of i
        int res = 0;
        int n = height.size();
        vector<int> dp(n, 0);
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            dp[i] = mx;
            mx = max(mx, height[i]);
        }
        mx = 0;
        for (int j = n - 1; j >= 0; --j) {
            dp[j] = min(mx, dp[j]);
            mx = max(mx, height[j]);
            if (dp[j] > height[j]) {
                res += dp[j] - height[j];
            }
        }
        return res;
    }
};

