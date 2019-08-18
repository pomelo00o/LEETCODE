/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */
class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        unordered_map<char, int> umap;
        for (auto c : t) umap[c]++;
        int left = 0, min = INT_MAX, cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            umap[s[i]]--;
            if (umap[s[i]] >= 0) cnt++;
            while (cnt == t.size()) {
                if (min > i - left + 1) {
                    min = i - left + 1;
                    res = s.substr(left, min);
                }
                umap[s[left]]++;
                if (umap[s[left]] > 0) cnt--;
                left++;
            }
        }
        return res;
    }
};

