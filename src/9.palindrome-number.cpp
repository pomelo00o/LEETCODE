/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0) return true;
        if (x < 0 || x % 10 == 0) return false;
        int a = 0;
        while (x > a) {
            a = a * 10 + x % 10;
            x /= 10;
        }
        return a == x || x == a / 10;
    }
};

