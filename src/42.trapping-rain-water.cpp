/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */
class Solution {
public:
    int trap(vector<int>& height) {
        // dp way
        // traverse 2 times
        // create a one-dimension dp[]
        // first traverse: dp[i] stores the greatest number on the left side of i
        // second traverse: dp[i] stores the greatest number on the right side of i
        
        // int res = 0;
        // int n = height.size();
        // vector<int> dp(n, 0);
        // int mx = 0;
        // for (int i = 0; i < n; ++i) {
        //     dp[i] = mx;
        //     mx = max(mx, height[i]);
        // }
        // mx = 0;
        // for (int j = n - 1; j >= 0; --j) {
        //     dp[j] = min(mx, dp[j]);
        //     mx = max(mx, height[j]);
        //     if (dp[j] > height[j]) {
        //         res += dp[j] - height[j];
        //     }
        // }
        // return res;

        // stack way
        // if curr > prev --> prev is a hole
        // if the hole has a left boundary, rain can be trapped
        stack<int> stk;
        int res = 0;
        int i = 0, n = height.size();
        while (i < n) {
            if (stk.empty() || height[i] <= height[stk.top()]) {
                stk.push(i);
                i++;
            } else {
                int t = stk.top();
                stk.pop();
                if (stk.empty()) continue;
                res += (min(height[i], height[stk.top()]) - height[t]) * (i - stk.top() - 1);
            }
        }
        return res;
    }
};

