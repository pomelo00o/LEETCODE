/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> umap;
        for (int n : nums) {
            umap[n] ++;
        }
        int i = 1;
        while (true) {
            if (umap.find(i) == umap.end()) return i;
            i ++;
        }
    }
};
// @lc code=end

