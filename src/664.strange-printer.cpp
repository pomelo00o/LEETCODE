/*
 * @lc app=leetcode id=664 lang=cpp
 *
 * [664] Strange Printer
 */
class Solution {
public:
    int strangePrinter(string s) {
        if (s.empty()) return 0;
        if (s.size() == 1) return 1;
        string ss;
        ss.push_back(s[0]);
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i -1]) continue;
            ss.push_back(s[i]);
        }
        s = ss;
        int sz = s.size();
        vector<vector<int>> dp(sz, vector<int>(sz, 0));
        for (int i = 0; i < sz; ++i) {
            dp[i][i] = 1;
            if (i < sz - 1) {
                dp[i][i + 1] = (dp[i][i] == dp[i][i + 1]) ? 1 : 2; 
            }
        }
        for (int len = 2; len < sz; ++len) {
            for (int start = 0; start + len < sz; ++start) {
                dp[start][start + len] = len + 1;
                for (int k = 0; k < len; ++k) {
                    int tmp = dp[start][start + k] + dp[start + k + 1][start + len];
                    dp[start][start + len] = 
                        min(dp[start][start + len], (s[start + k] == s[start + len]) ? tmp - 1 : tmp);
                }
            }
        }
        return dp[0][sz - 1];
    }
};

