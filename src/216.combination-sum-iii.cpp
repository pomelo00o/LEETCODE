/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> combinations;
        vector<int> curr;
        backtrack(combinations, curr, k, n, 1);
        return combinations;
    }

    void backtrack(vector<vector<int>>& combinations, vector<int>& curr, int k, int n, int start) {
        if (n < 0 || k < 0) {
            return;
        }
        if (n == 0 && k == 0) {
            combinations.push_back(curr);
            return;
        }
        for (int i = start; i < 10; ++i) {
            curr.push_back(i);
            backtrack(combinations, curr, k - 1, n - i, i + 1);
            curr.pop_back();
        }
    }
};

