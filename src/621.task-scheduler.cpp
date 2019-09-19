/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // the idea is to first find out the element with  highest frequency, eg: A in this case
        // suppose there are a total of m A's
        // the location of each A should be [0, n + 1, 2(n + 1), ..., m(n + 1)]
        // the length from head to just before the last A is (m - 1)(n + 1)
        // for all elements with the same frequency m, they are located just after (m - 1)(n + 1), thus adding one for each
        // consider the most tricky part: if n < #other vars, then it can be proven that other variables can be inserted straightforwardly into the empty slot, thus having the total length to be tasks.size()
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

