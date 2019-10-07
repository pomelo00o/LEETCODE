/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        string res = "", t = "";
        stringstream ss(path);
        vector<string> v;
        while (getline(ss, t, '/')) {
            if (t == "." || t == "") continue;
            else if (t == ".." && !v.empty()) {
                v.pop_back();
            } else if (t != "..") {
                v.push_back(t);
            }
        }
        for (string s : v) {
            res += "/" + s;
        }
        return res.empty() ? "/" : res;
    }
};
// @lc code=end

