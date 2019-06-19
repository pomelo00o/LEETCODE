class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> set;
        for (int i = 0; i < emails.size(); ++i) {
            set.insert(parse(emails[i]));
        }
        return set.size();
    }
    string parse(string email) {
        string res = "";
        bool skip = false;
        bool isAT = false;
        for (int i = 0; i < email.size(); ++i) {
            if (isAT) {
                break;
            }
            char c = email[i];
            switch (c) {
            case '.':
                break;
            case '+':
                skip = true;
                break;
            case '@':
                isAT = true;
                for (int j = i; j < email.size(); ++j) {
                    res.push_back(email[j]);
                }
                break;
            default:
                if (!skip) {
                    res.push_back(c);
                }
                break;
            }
        }
        std::cout<<res<<std::endl;
        return res;
    }
};