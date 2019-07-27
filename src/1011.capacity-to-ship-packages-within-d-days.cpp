/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = 0, right = 0;
        for (auto w : weights) {
            left = max(left, w);
            right += w;
        }
        while (left < right) {
            int mid = (left + right) / 2;
            int day = 1, load = 0;
            for (auto w : weights) {
                if (load + w > mid) { // overload
                    day += 1;
                    load = 0;
                }
                load += w;
            }
            if (day > D) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};

