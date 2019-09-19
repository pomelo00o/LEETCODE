/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> umap;
        for (int i = 0; i < order.size(); ++i) {
            umap[order[i]] = i;
        }
        for (string& word : words) {
            for (char& c : word) {
                c = umap[c];
            }
        }
        return is_sorted(words.begin(), words.end());
    }
};

