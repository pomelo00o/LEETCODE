/*
 * @lc app=leetcode id=324 lang=cpp
 *
 * [324] Wiggle Sort II
 */
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1) return;
        int left = 0;
        int maxEle = nums[left];
        while (left < nums.size()) {
            for (int i = left + 1; i < nums.size(); ++i) {
                if (nums[i] < nums[left]) {
                    swap(nums[i], nums[left]);
                } else {
                    maxEle = max(nums[left], maxEle);
                }
            }
            left += 1;
        }
    }
};

