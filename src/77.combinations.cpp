/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> curr;
        backtrack(n, k, 1, combinations, curr);
        return combinations;
    }

    void backtrack(int n, int k, int start, vector<vector<int>>& combinations, vector<int>& curr) {
        if (k == 0) {
            combinations.push_back(curr);
        } else {
            for (int i = start; i <= n - k + 1; ++i) {
                curr.push_back(i);
                backtrack(n, k - 1, i + 1, combinations, curr);
                curr.pop_back();
            }
        }
    }
};

