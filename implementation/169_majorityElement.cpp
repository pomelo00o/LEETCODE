class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        auto size = nums.size();
        for (auto i = 0; i < size; ++i) {
        	count[nums[i]]++;
        	if (count[nums[i]] > size / 2) {
        		return nums[i];
        	}
        }
    }
};