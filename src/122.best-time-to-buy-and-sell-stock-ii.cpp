/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        if (prices.size() < 2) return 0;
        for (int i = 0; i < prices.size() - 1; ++i) {
            profit += max(prices[i + 1] - prices[i], 0);
        }
        return profit;
    }
};

