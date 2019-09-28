/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */
class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty() && b.empty()) return "";
        if (a.empty()) return b;
        if (b.empty()) return a;
        string res = "";
        int m = a.size() - 1, n = b.size() - 1;
        int carry = 0;
        while (m >= 0 || n >= 0) {
            int s = m >= 0 ? (a[m] - '0') : 0, t = n >= 0 ? (b[n] - '0') : 0;
            int sum = s + t + carry;
            carry = sum / 2;
            sum %= 2;
            res = to_string(sum) + res;
            m --; n --;
        }
        if (carry == 1) {
            res = "1" + res;
        }
        return res;
    }
};

