/*
 * @lc app=leetcode id=301 lang=cpp
 *
 * [301] Remove Invalid Parentheses
 */
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0;
        for (auto &c : s) {
            if (c == '(') l ++;
            if (c == ')') {
                if (l > 0) l --;
                else r ++;
            }
        }
        vector<string> res;
        dfs(s, 0, l, r, res);
        return res;
    }

    bool isValid(string s) {
        int cnt = 0;
        for (auto &c : s) {
            if (c == '(') cnt ++;
            if (c == ')') cnt --;
            if (cnt < 0) return false;
        }
        return cnt == 0;
    }

    void dfs(string& s, int start, int l, int r, vector<string>& res) {
        if (l == 0 && r == 0) {
            if (isValid(s)) res.push_back(s);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            if (i > start && s[i] == s[i - 1]) continue;
            if (s[i] == '(' || s[i] == ')') {
                string tmp = s;
                tmp.erase(i, 1);
                if (r > 0 && s[i] == ')') {
                    dfs(tmp, i, l, r - 1, res);
                } else {
                    dfs(tmp, i, l - 1, r, res);
                }
            }
        }
    }
};

