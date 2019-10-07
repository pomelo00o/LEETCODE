/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 */
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res = {};
        for (int i = 0, j = 0; i < A.size() && j < B.size();) {
            vector<int> tempA = A[i], tempB = B[j];
            if (tempA[1] < tempB[0]) {
                i ++;
            } else if (tempB[1] < tempA[0]) {
                j ++;
            } else {
                vector<int> out = {max(tempA[0], tempB[0]), min(tempA[1], tempB[1])};
                res.push_back(out);
                if (tempA[1] > tempB[1]) {
                    j ++;
                } else {
                    i ++;
                }
            }
        }
        return res;
    }
};

