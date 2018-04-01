class Solution {
public:
    int singleNumber(vector<int>& nums) {
        auto result = 0;
        auto size = nums.size();
        for (auto i = 0; i < size; ++i) {
        	result ^= nums[i];
        }
        return result;
    }
};