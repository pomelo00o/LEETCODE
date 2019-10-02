/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 */
class Solution {
private:
    vector<int> accu_weight;
public:
    Solution(vector<int>& w) {
        accu_weight = w;
        for (int i = 1; i < w.size(); ++i) {
            accu_weight[i] = w[i] + accu_weight[i - 1];
        }
    }
    
    int pickIndex() {
        int total_weight = accu_weight.back();
        int randIdx = rand() % total_weight;
        int left = 0, right = accu_weight.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (accu_weight[mid] <= randIdx) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        // an alternative way is to use upper_bound(accu_wight.begin(), accu_weight.end(), randIdx)
        return right;
    }

    // Tips: lower_bound returns n >= target
    //       upper_bound returns n > target 
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

