/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        vector<vector<int>> merge;
        sort(intervals.begin(), intervals.end());
        merge.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            vector<int> curr = merge.back();
            vector<int> next = intervals[i];
            if (curr[1] < next[0]) {
                merge.push_back(next);
            } else {
                merge.back()[1] = max(curr[1], next[1]);
            }
        }
        return merge;
    }
};

