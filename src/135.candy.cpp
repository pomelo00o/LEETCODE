/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */
class Solution {
public:
    int candy(vector<int>& ratings) {
        int sz = ratings.size();
        vector<int> dp(sz, 1);
        for (int i = 1; i < sz; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
        }
        for (int i = sz - 1; i > 0; --i) {
            if (ratings[i - 1] > ratings[i]) {
                dp[i - 1] = max(dp[i - 1], dp[i] + 1);
            }
        }
        int cnt = 0;
        for (auto e : dp) {
            cnt += e;
        }
        return cnt;
    }
};

