/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() >= 2) {
            int tmp1 = pq.top();
            pq.pop();
            int tmp2 = pq.top();
            pq.pop();
            if (tmp1 != tmp2) pq.push(tmp1 - tmp2);
        }
        if (pq.empty()) return 0;
        else return pq.top();
    }
};

