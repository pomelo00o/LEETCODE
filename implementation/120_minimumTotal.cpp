class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> result = triangle.back();
    	for (auto i = triangle.size() - 2; i >= 0; --i) {
        	for (auto j = 0; j <= i; ++j) {
            	result[j] = triangle[i][j] + min(result[j], result[j + 1]);
        	}
    	}
    	return result[0];
    }
};