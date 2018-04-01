class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        auto size = nums.size();
        for (auto i = 0; i < size; ++i) {
        	auto index = abs(nums[i]) - 1;
        	nums[index] = nums[index] > 0 ? -nums[index] : nums[index];
        }
        vector<int> result;
        for (auto i = 0; i < size; ++i) {
        	if (nums[i] > 0) {
        		result.push_back(i + 1);
        	}
        }
        return result;
    }
};