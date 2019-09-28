/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        int start = 0, end = s.size() - 1;
        while (start < end) {
            while (start < end && !isalnum(s[start])) {
                start ++;
            }
            while (start < end && !isalnum(s[end])) {
                end --;
            }
            if (tolower(s[start]) != tolower(s[end])) return false;
            start ++; end --;
        }
        return true;
    }
};

