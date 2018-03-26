class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto index = 0;
        for (auto i = 0; i < nums.size(); ++i) {
        	if (nums[i] != 0) {
        		nums[index++] = nums[i];
        	}
        }
        for (auto i = index; i < nums.size(); ++i) {
        	nums[i] = 0;
        }
    }
};