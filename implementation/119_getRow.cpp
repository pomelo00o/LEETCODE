class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1, 1);
		for(int i = 1; i < result.size()-1; ++i) {
			for(int j = rowIndex - 1; j >=i; --j) {
				result[j] = result[j + 1] + result[j];
			}
		}
		return result;
    }
};