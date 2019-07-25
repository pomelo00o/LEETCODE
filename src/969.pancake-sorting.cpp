/*
 * @lc app=leetcode id=969 lang=cpp
 *
 * [969] Pancake Sorting
 */
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> res;
        for (int m = A.size(); m > 0; --m) {
            int i = 0;
            while (A[i] != m) i += 1;
            reverse(A.begin(), A.begin() + i + 1);
            res.push_back(i + 1);
            reverse(A.begin(), A.begin() + m);
            res.push_back(m);
        }
        return res;
    }
};
