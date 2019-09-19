/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> dict;
        for (int a : nums1) {
            dict[a] ++;
        }
        for (int b : nums2) {
            if (dict[b] > 0) {
                res.push_back(b);
                dict[b] --;
            }
        }
        return res;
    }
};

