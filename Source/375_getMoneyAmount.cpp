class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (auto i = 1; i <= n; ++i){
            for (auto j = i - 1; j >= 1; --j){
                int min_value = INT_MAX;
                for (auto k = j; k <= i; ++k){
                    auto tmp = k + max(dp[j][k - 1], dp[k + 1][i]);
                    min_value = min(min_value, tmp);
                }
                dp[j][i] = min_value;
            }
        }
        return dp[1][n];
    }
};