/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, n = s.size(), left = -1;
        unordered_map<char, int> umap;
        for (int i = 0; i < n; ++i) {
            if (umap.find(s[i]) != umap.end() && umap[s[i]] > left) {
                left = umap[s[i]];
            }
            umap[s[i]] = i;
            res = max(res, i - left);
        }
        return res;
    }
};
// @lc code=end

