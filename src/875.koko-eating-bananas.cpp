/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int left = 1, right = 1e9;
        while (left < right) {
            int mid = (left + right) / 2;
            int cnt = 0;
            for (auto pile : piles) cnt += (pile + mid - 1) / mid;
            if (cnt > H) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};

