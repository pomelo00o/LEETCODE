/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // For example, we are given a vector [2, 3, 4, 5]
        // In order to calculate the answer for element 4, basically we need a left vector [2, 3] and a right vector [5]
        // thus, we can have left = [1, 2, 2 * 3, 2 * 3 * 4]
        // and right = [1, 5, 4 * 5, 3 * 4 * 5]
        int sz = nums.size();
        vector<int> res(sz);
        vector<int> left(sz, 1);
        vector<int> right(sz, 1);
        for (int i = 1; i < sz; ++i) {
            left[i] = left[i - 1] * nums[i - 1];
            right[i] = right[i - 1] * nums[sz - i];
        }
        for (int i = 0; i < sz; ++i) {
            res[i] = left[i] * right[sz - i - 1];
        }
        return res;
    }
};

