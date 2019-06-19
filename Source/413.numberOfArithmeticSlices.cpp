class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        auto cnt = 0;
        vector<int> dp;
        auto size = A.size();
        if (size < 3) {
        	return cnt;
        }
        for (auto i = 0; i < size; ++i) {
        	dp.push_back(0);
        }
        for (auto i = 2; i < size; ++i) {
        	if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
        		dp[i] = dp[i - 1] + 1;
        		cnt += dp[i];
        	} else {
        		dp[i] = 0;
        	}
        }
        return cnt;
    }
};