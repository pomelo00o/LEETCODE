/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> umap;
        for (auto &c : s) {
            umap[c] ++;
        }
        for (auto &c : t) {
            umap[c] --;
        }
        for (auto &e : umap) {
            if (e.second != 0) return false;
        }
        return true;
    }
};

