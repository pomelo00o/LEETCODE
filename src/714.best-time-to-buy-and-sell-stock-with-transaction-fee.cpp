/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int maxSum = 0;
        int sz = prices.size();
        vector<int> buy(sz, 0);
        vector<int> sell(sz, 0);
        buy[0] = -prices[0], sell[0] = 0;
        for (int i = 1; i < sz; ++i) {
            buy[i] = max(buy[i - 1], sell[i - 1] - prices[i]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i] - fee);
        }
        return sell[sz - 1];
    }
};

