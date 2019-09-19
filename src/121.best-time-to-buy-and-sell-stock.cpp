/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxCurr = 0, maxSoFar = 0;
        for (int i = 1; i < prices.size(); ++i) {
            maxCurr = max(0, maxCurr += prices[i] - prices[i - 1]);
            maxSoFar = max(maxSoFar, maxCurr);
        }
        return maxSoFar;
    }
};

