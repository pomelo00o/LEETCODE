/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {   
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, curr = 0;
        while (curr <= right) {
            if (nums[curr] == 0) {
                swap(nums[curr], nums[left]);
                curr ++;
                left ++;
            } else if (nums[curr] == 2) {
                swap(nums[curr], nums[right]);
                right --;
            } else {
                curr ++;
            }
        }
    }
};
// @lc code=end

