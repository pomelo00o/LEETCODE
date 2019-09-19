/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 */
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int res = 0, mx = 0, n = nums.size();
        vector<int> len(n, 1), cnt(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] >= nums[i]) {
                    // not a increasing sequence
                    continue;
                }
                if (len[i] == len[j] + 1) {
                    // if the i-th element can be directly appended to the j-th element
                    cnt[i] += cnt[j];
                } else if (len[i] < len[j] + 1) {
                    // find a longer sequence
                    len[i] = len[j] + 1;
                    cnt[i] = cnt[j];
                }
            }
            mx = max(mx, len[i]); // mx: maximum length
        }
        for (int i = 0; i < n; ++i) {
            if (mx == len[i]) {
                res += cnt[i];
            }
        }
        return res;
    }
};

