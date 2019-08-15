/*
 * @lc app=leetcode id=1054 lang=cpp
 *
 * [1054] Distant Barcodes
 */
typedef pair<int, int> pii;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int> res;
        priority_queue<pii> pq;
        unordered_map<int, int> umap;
        for (auto bc : barcodes)
            umap[bc] += 1;
        for (auto u : umap) // u: <freq, val>
            pq.push({u.second, u.first});
        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            if (res.empty() || res.back() != t.second || pq.empty()) {
                res.push_back(t.second);
                t.first -= 1;
                if (t.first > 0)
                    pq.push(t);
            } else {
                auto s = pq.top();
                pq.pop();
                pq.push(t);
                res.push_back(s.second);
                s.first -= 1;
                if (s.first > 0)
                    pq.push(s);
            }
        }
        return res;
    }
};

