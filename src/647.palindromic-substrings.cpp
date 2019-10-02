/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
private:
    int cnt = 0;
    void extendPalindrome(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            cnt ++;
            left --;
            right ++;
        }
    }
public:
    int countSubstrings(string s) {
        if (s.empty()) return 0;
        for (int i = 0; i < s.size(); ++i) {
            extendPalindrome(s, i, i); // middle is s[i]
            extendPalindrome(s, i, i + 1); // middle is s[i], '', s[j]
        }
        return cnt;
    }
};
// @lc code=end

