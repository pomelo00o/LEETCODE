/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res = {};
        if (s.empty() || words.empty()) return res;
        unordered_map<string, int> umap;
        for (string w : words) {
            umap[w] ++;
        }
        int n = s.size(), num = words.size(), len = words[0].size();
        for (int i = 0; i < n - num * len + 1; ++i) {
            unordered_map<string, int> seen;
            int j = 0;
            for (j = 0; j < num; ++j) {
                string word = s.substr(i + j * len, len);
                if (umap.find(word) != umap.end()) {
                    seen[word] ++;  
                    if (seen[word] > umap[word]) break;
                } else {
                    break;
                }
            }
            if (j == num) {
                res.push_back(i);
            }
        }
        return res;
    }
};
// @lc code=end

