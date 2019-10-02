/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, buy = INT_MAX;
        for (auto p : prices) {
            buy = min(buy, p);
            profit = max(profit, p - buy);
        }
        return profit;
    }
};

