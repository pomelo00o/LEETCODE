/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 */
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<int, int> union_find;
        unordered_map<string, int> m;
        for (int i = 0; i < accounts.size(); ++i) {
            union_find[i] = i;
            for (int j = 1; j < accounts[i].size(); ++j) {
                if (m.find(accounts[i][j]) != m.end()) {
                    int currIdx = find(union_find, i);
                    int prevIdx = find(union_find, m[accounts[i][j]]);
                    union_find[currIdx] = prevIdx;
                } else {
                    m[accounts[i][j]] = union_find[i];
                }
            }
        }
        unordered_map<int, vector<string>> emails;
        for (auto it : m) {
            int idx = find(union_find, it.second);
            emails[idx].push_back(it.first);
        }
        vector<vector<string>> res;
        for (auto it : emails) {
            vector<string> email = it.second;
            sort(email.begin(), email.end());
            email.insert(email.begin(), accounts[it.first][0]);
            res.push_back(email);
        }
        return res;
    }

    int find(map<int, int>& union_find, int idx) {
        while (union_find[idx] != idx) {
            idx = union_find[idx];
        }
        return idx;
    }
};

