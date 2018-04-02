class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curMax = nums[0], preMax = nums[0];
        auto size = nums.size();
        for (auto i = 1; i < size; ++i) {
            preMax = max(preMax + nums[i], nums[i]);
            curMax = max(curMax, preMax);
        }
        return curMax;
    }
};