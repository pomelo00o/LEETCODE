/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */
class Solution {
private:
    int minLen = INT_MAX;
    int cnt = 0;
public:
    string minWindow(string s, string t) {
        string res = "";
        unordered_map<char, int> umap;
        for (char &c : t) {
            umap[c] ++;
        }
        int left = 0;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            umap[c] --;
            if (umap[c] >= 0) { // c is in T
                cnt ++;
            }
            while (cnt == t.size()) { // contain all char in T
                if (minLen > i - left + 1) {
                    minLen = i - left + 1;
                    res = s.substr(left, minLen);
                }
                char leftmost = s[left];
                umap[leftmost] ++;
                if (umap[leftmost] > 0) {
                    cnt --;
                }
                left ++;
            }
        }
        return res;
    }
};

