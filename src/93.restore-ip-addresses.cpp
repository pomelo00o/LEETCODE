/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        resotre(s, 4, "", res);
        return res;
    }

    void resotre(string s, int k, string out, vector<string>& res) {
        if (k == 0) {
            if (s.empty())
                res.push_back(out);
        } else {
            for (int i = 1; i <= 3; ++i) {
                string segment = s.substr(0, i);
                if (s.size() >= i && isValid(segment)) {
                    if (k == 1)
                        resotre(s.substr(i), 0, out + segment, res);
                    else
                        resotre(s.substr(i), k - 1, out + segment + ".", res);
                }
            }
        }
    }

    bool isValid(string s) {
        if (s.size() > 3 || s.empty() || (s.size() > 1 && s[0] == '0'))
            return false;
        int n = atoi(s.c_str());
        return n >= 0 && n <= 255;
    }
};

