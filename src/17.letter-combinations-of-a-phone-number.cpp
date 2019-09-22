/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */
class Solution {
private:
    unordered_map<char, string> umap = 
        {{'2', "abc"},  {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> combinations;
        string curr;
        backtrack(combinations, curr, digits);
        return combinations;
    }

    void backtrack(vector<string>& combinations, string curr, string digits) {
        int sz = curr.size();
        if (sz == digits.size()) {
            combinations.push_back(curr);
            return;
        }
        char c = digits[sz];
        string letters = umap[c];
        for (int i = 0; i < letters.size(); ++i) {
            curr.push_back(letters[i]);
            backtrack(combinations, curr, digits);
            curr.pop_back();
        }
    }
};

