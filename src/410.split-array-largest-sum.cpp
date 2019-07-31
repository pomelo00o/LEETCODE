/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long left = 0, right = 0;
        for (auto num : nums) {
            left = max(left, (long long)num);
            right += num;
        }
        while (left < right) {
            long long mid = (left + right) / 2;
            if (helper(nums, mid, m - 1)) right = mid;
            else left = mid + 1;
        }
        return left;
    }

    bool helper(vector<int>& nums, long long max, int cuts) {
        int cnt = 0;
        for (auto num : nums) {
            if (cnt + num <= max) cnt += num;
            else {
                --cuts;
                cnt = num;
                if (cuts < 0) return false;
            }
        }
        return true;
    }
};

