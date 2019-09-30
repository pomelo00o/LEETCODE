/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
class Solution {
public:
    string longestPalindrome(string s) {
        string t = preprocess(s);
        vector<int> p(t.size(), 0);
        // mx: right most place that a palindrome can reach
        // id: center for the above palindrome
        // radius: current longest radius
        // center: center for the above radius
        int mx = 0, id = 0, radius = 0, center = 0;
        for (int i = 1; i < t.size(); ++i) {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 0;
            while (t[i - p[i]] == t[i + p[i]]) {
                p[i] ++;
            }
            if (mx < i + p[i]) {
                mx = i + p[i];
                id = i;
            }
            if (radius < p[i]) {
                radius = p[i];
                center = i;
            }
        }
        int start = (center - radius) / 2, len = radius - 1;
        return s.substr(start, len);
    }

    string preprocess(string s) {
        string t = "$#";
        for (char& c : s) {
            t += c;
            t += '#';
        }
        return t;
    }
};

