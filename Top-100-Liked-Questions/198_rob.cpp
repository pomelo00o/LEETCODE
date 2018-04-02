class Solution {
public:
    int rob(vector<int>& nums) {
        auto size = nums.size();
        if (size == 0) return 0;
        if (size == 1) return nums[0];
        if (size == 2) return max(nums[0], nums[1]);
        vector<int> f(size, 0);
        f[0] = nums[0];
        f[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; ++i) {
            f[i] = max(f[i - 2] + nums[i], f[i - 1]);
        }
        return f[size - 1];
    }
};