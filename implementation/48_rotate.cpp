class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        auto len = matrix.size();
        for (auto i = 0; i < len; ++i) {
            for (auto j = i + 1; j < len; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};