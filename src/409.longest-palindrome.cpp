/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> dictionary;
        for (char& c : s) {
            dictionary[c] ++;
        }
        int cnt = 0;
        bool mid = false;
        for (auto e : dictionary) {
            cnt += e.second;
            if (e.second % 2 == 1) {
                cnt -= 1;
                mid = true;
            }
        }
        return mid ? cnt + 1 : cnt;
    }
};

