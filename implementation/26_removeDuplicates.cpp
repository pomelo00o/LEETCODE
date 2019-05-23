class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int walker = 0, runner = 0;
		for (runner = 0; runner < nums.size(); ++runner) {
			if (nums[walker] != nums[runner]) {
				++walker;
				nums[walker] = nums[runner];
			}
		}
		return walker + 1;
	}
};