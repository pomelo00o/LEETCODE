/*
 * @lc app=leetcode id=825 lang=cpp
 *
 * [825] Friends Of Appropriate Ages
 */
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int res = 0;
        vector<int> a(121, 0);
        // from rule 1: 0.5a+7 <= a --> a >= 15
        for (auto age : ages) {
            a[age] ++;
        }
        for (int i = 15; i <= 120; ++i) {
            for (int j = 0.5 * i + 8; j <= i; ++j) {
                res += a[j] * (a[i] - (i == j));
            }
        }
        return res;
    }
};

