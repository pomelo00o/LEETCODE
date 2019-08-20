/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            vector<int> tmp = intervals[i];
            vector<int> last = res.back();
            if (last[1] < tmp[0]) // no overlapping
                res.push_back(tmp);
            else
                res.back()[1] = max(tmp[1], last[1]);
        }
        return res;
    }
};

