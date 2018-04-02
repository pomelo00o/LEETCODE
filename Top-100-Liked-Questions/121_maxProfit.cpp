class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto maxPro = 0;
        auto minPri = INT_MAX;
        auto size = prices.size();
        for (auto i = 0; i < size; ++i) {
        	minPri = min(prices[i], minPri);
        	maxPro = max(maxPro, prices[i] - minPri);
        }
        return maxPro;
    }
};