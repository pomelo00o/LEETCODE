/*
 * @lc app=leetcode id=480 lang=cpp
 *
 * [480] Sliding Window Median
 */
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<int> small, large;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) {
                int tmp = nums[i - k];
                if (small.count(tmp)) small.erase(small.find(tmp));
                else large.erase(large.find(tmp));
            }
            int curr = nums[i];
            if (small.size() <= large.size()) {
                if (large.empty() || curr <= *(large.begin())) small.insert(curr);
                else {
                    large.insert(curr);
                    small.insert(*(large.begin()));
                    large.erase(large.begin());
                }
            } else {
                if (curr >= *(small.rbegin())) large.insert(curr);
                else {
                    small.insert(curr);
                    large.insert(*(small.rbegin()));
                    small.erase(--small.end());
                }
            }
            if (i >= k - 1) {
                double c;
                if (k % 2 == 0) c = (((double)*(small.rbegin()) + (double)*(large.begin())) / 2);
                else c = *(small.rbegin());
                res.push_back(c);
            }
        }
        return res;
    }
};

