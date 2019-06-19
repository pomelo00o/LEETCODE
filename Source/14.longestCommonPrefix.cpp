class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	if (strs.empty()) {
            return "";
        }
        string res = "";
        for (int j = 0; j < strs[0].size(); ++j) {
            char ch = strs[0][j];
            for (int i = 1; i < strs.size(); ++i) {
                if (strs[i][j] != ch || j > strs[i].size()) {
                    return res;
                }
            }
            res.push_back(ch);
        }
        return res;
    }
};