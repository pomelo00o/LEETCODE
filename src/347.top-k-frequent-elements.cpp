/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    struct comp
    {
        bool operator()(pair<int, int> p, pair<int, int> q) {
            return p.first < q.first;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> umap; // (n -> freq)
        for (int n : nums) {
            umap[n] ++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq; // (freq -> num)
        for (auto e : umap) {
            pq.push({e.second, e.first});
        }
        for (int i = 0; i < k; ++i) {
            auto p = pq.top();
            pq.pop();
            res.push_back(p.second);
        }
        return res;
    }
};
// @lc code=end

