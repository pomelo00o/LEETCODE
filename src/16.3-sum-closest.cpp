/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        int min_diff = abs(res - target);
        for (int i = 0; i < nums.size(); ++i) {
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int diff = abs(sum - target);
                if (diff < min_diff) {
                    res = sum;
                    min_diff = diff;
                }
                if (sum < target) {
                    left += 1;
                } else {
                    right -= 1;
                }
            }
        }
        return res;
    }
};

