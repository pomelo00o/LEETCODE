/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        if (intervals.size() == 1) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res{intervals[0]};
        for (int i = 1; i < intervals.size(); ++i) {
            auto tmp = intervals[i];
            auto last = res.back();
            if (tmp[0] > last[1]) {
                // no overlapping
                res.push_back(tmp);
            } else {
                res.back()[1] = max(tmp[1], last[1]);
            }
        }
        return res;
    }
};

