/*
 * @lc app=leetcode id=969 lang=cpp
 *
 * [969] Pancake Sorting
 */
using namespace std;
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> res;
        helper(res, A);
        reverse(res.begin(), res.end());
        return res;
    }

    void helper(vector<int>& res, vector<int>& A) {
        if (A.empty()) return;
        int size = A.size();
        auto maxPos = max_element(A.begin(), A.end()) - A.begin();
        if (maxPos != 0) reverse(A.begin(), A.begin() + maxPos + 1);
        reverse(A.begin(), A.end());
        auto max = A[size - 1];
        A.erase(A.begin() + size - 1);
        res.push_back(max);
        helper(res, A);
    }
};
