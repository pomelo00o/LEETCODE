/*
 * @lc app=leetcode id=507 lang=cpp
 *
 * [507] Perfect Number
 */
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) return false;
        int res = 1;
        for (int i = 2; pow(i, 2) < num; ++i) {
            if (num % i == 0 && i != num) {
                res += (i + num / i);
            }
        }
        return res == num;
    }
};

