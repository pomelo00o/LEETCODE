/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        string res = "";
        unordered_map<char, int> umap; // char -> freq
        for (char c : s) {
            umap[c] ++;
        }

        vector<vector<char>> buckets(s.size() + 1);
        for (auto e : umap) {
            int freq = e.second;
            char c = e.first;
            for (int i = 0; i < freq; ++i) {
                buckets[freq].push_back(c);
            }
        }

        for (int i = s.size(); i >= 0; --i) {
            vector<char> curr = buckets[i];
            if (!curr.empty()) {
                sort(curr.begin(), curr.end());
                for (auto c : curr) {
                    res.push_back(c);
                }
            }
        }
        return res;
    }
};
// @lc code=end

