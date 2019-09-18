/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int m = a.size() - 1, n = b.size() - 1;
        int carry = 0;
        while (m >= 0 || n >= 0) {
            int p = m >= 0 ? a[m] - '0' : 0;
            int q = n >= 0 ? b[n] - '0' : 0;
            int sum = p + q + carry;
            res = to_string(sum % 2) + res;
            carry = sum / 2;
            m--; n--;
        }
        if (carry == 1) return '1' + res;
        return res;
    }
};

