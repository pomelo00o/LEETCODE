/*
 * @lc app=leetcode id=324 lang=cpp
 *
 * [324] Wiggle Sort II
 */
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        auto tmp = nums;
        sort(tmp.begin(), tmp.end());
        int n = nums.size(), k = (n + 1) / 2;
        for (int i = 0; i < nums.size(); ++i) {
            if (i % 2 == 0)
                nums[i] = tmp[--k];
            else
                nums[i] = tmp[--n];
        }
    }
};

