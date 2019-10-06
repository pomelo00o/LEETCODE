/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                j ++;
            }
        }
        while (j < n) {
            nums[j] = 0;
            j ++;
        }
    }
};
// @lc code=end

