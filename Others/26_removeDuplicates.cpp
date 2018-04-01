class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		auto i = 0;
		auto j = 1;
		if (nums.empty()) {
			return 0;
		}
		for(i = 1; i < nums.size(); ++i)
		{
			if (nums[i] == nums[i - 1]) {
				continue;
			} else {
				nums[j++]=nums[i];
			}
		}
		return  j;
	}
};