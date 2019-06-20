/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */
class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 1; i < n; ++i) {
            res = helper(res);
        }
        return res;
    }
    string helper(string m) {
        string res = "";
        auto first = 0;
        auto index = first;
        while (first < m.size()) {
            auto cnt = 0;
            while (m[index] == m[first]) {
                cnt += 1;
                index += 1;
            }
            res += to_string(cnt) + m[first];
            first = index;
        }
        return res;
    }
};

