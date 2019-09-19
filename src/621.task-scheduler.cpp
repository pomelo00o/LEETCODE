/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> umap;
        int cnt = 0;
        for (auto t : tasks) {
            umap[t] ++;
            cnt = max(cnt, umap[t]);
        }
        int res = (cnt - 1) * (n + 1);
        for (auto e : umap) {
            if (e.second == cnt) {
                res ++;
            }
        }
        return max(res, (int)tasks.size());
    }
};

