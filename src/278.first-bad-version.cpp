/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s = 1, e = n;
        while (s < e) {
            int mid = s + (e - s) / 2; // in case of overflow when two large integers doing addition
            if (isBadVersion(mid)) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }
        return s;
    }
};

