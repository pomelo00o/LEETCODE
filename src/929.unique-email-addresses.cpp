/*
 * @lc app=leetcode id=929 lang=cpp
 *
 * [929] Unique Email Addresses
 */
class Solution {
private:
    unordered_set<string> uset;
public:
    int numUniqueEmails(vector<string>& emails) {
        for (string email : emails) {
            string e = reshape(email);
            uset.insert(e);
        }
        return uset.size();
    }

    string reshape(string email) {
        string e = "";
        int sep = 0;
        bool skip = false;
        for (int i = 0; i < email.size(); ++i) {
            char c = email[i];
            if (c == '.')
                continue;
            else if (c == '+') {
                skip = true;
                continue;
            }
            else if (c == '@') {
                sep = i;
                for (int j = i; j < email.size(); ++j)
                    e.push_back(email[j]);
                break;
            }
            else {
                if (!skip)
                    e.push_back(c);
            }
        }
        return e + email.substr(sep + 1);
    }
};

