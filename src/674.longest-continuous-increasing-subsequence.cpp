/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 */
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int curr = INT_MAX, res = 0, cnt = 0;
        for (int n : nums) {
            if (n > curr) {
                cnt ++;
            } else {
                cnt = 1;
            }
            res = max(res, cnt);
            curr = n;
        }
        return res;
    }
};

