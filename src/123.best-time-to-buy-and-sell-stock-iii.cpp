/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
public:
    // local[i][j]: j-th trade (could be a buy or a sell) on day i-th, max profit
    // global[i][j]: j-th trade within i day, max profit
    // --------------------------------------------------------------
    // on the i-th day
    // --------------------------------------------------------------
    // if exec a buy: this day's profit will not be counted
    // local[i][j] = global[i - 1][j - 1]
    // --------------------------------------------------------------
    // if exec a sell:
    // local[i][j] = global[i - 1][j - 1] + diff
    //          or = local[i - 1][j] + diff (did a sell yesterday, now want to sell today)
    // --------------------------------------------------------------
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        vector<vector<int>> g(n, vector<int>(3, 0)), l(n, vector<int>(3, 0));
        for (int i = 1; i < n; ++i) {
            int diff = prices[i] - prices[i - 1];
            for (int j = 1; j <= 2; ++j) {
                l[i][j] = diff + max(g[i - 1][j - 1], l[i - 1][j]);
                g[i][j] = max(g[i - 1][j], l[i][j]);
            }
        }
        return g[n - 1][2];
    }
};
// @lc code=end

