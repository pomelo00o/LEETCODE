class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            vector<string> vec;
            return vec;
        }
        string num2letter[] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result(1, "");
        for (auto i = 0; i < digits.size(); ++i) {
            vector<string> temp;
            for (auto j = 0; j < result.size(); ++j) {
                for(auto k = 0; k < num2letter[digits[i] - '0'].size(); ++k) {  
                    temp.push_back(result[j] + num2letter[digits[i] - '0'][k]);  
                }
            }
            result = temp;
        }
        return result;
    }
};