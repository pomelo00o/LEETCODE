/*
 * @lc app=leetcode id=468 lang=cpp
 *
 * [468] Validate IP Address
 */
class Solution {
public:
    string validIPAddress(string IP) {
        string neither = "Neither";
        string ipv4 = "IPv4";
        string ipv6 = "IPv6";
        istringstream is(IP);
        string t = "";
        int cnt = 0;
        if (IP.find(':') == string::npos) { // ipv4
            while (getline(is, t, '.')) {
                cnt++;
                if (cnt > 4 || t.empty() || (t.size() > 1 && t[0] == '0') || t.size() > 3)
                    return neither;
                for (char c : t) {
                    if (c < '0' || c > '9') return neither;
                }
                int val = atoi(t.c_str());
                if (val > 255 || val < 0) return neither;
            }
            return (cnt == 4 && IP.back() != '.') ? ipv4 : neither;
        } else { // ipv6
            while (getline(is, t, ':')) {
                cnt++;
                if (cnt > 8 || t.empty() || t.size() > 4)
                    return neither;
                for (char c : t) {
                    if (!(c >= '0' && c <= '9') && !(c >= 'a' && c <= 'f') && !(c >= 'A' && c <= 'F'))
                        return neither;
                }
            }
            return (cnt == 8 && IP.back() != ':') ? ipv6 : neither;
        }
    }
};

