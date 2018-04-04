class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	vector<vector<int>> result;
    	result.clear();
    	sort(nums.begin(), nums.end());
        for (auto i = 0; i < nums.size(); ++i) {
            auto start = i + 1;
            auto end = nums.size() - 1;
            auto target = - nums[i];
            while (start < end) {
                auto sum = nums[start] + nums[end];
                if (sum > target) {
                    end--;
                } else if (sum < target) {
                    start++;
                } else {
                    vector<int> temp;
                    temp.clear();
                    temp.push_back(nums[i]);
                    temp.push_back(nums[start]);
                    temp.push_back(nums[end]);
                    result.push_back(temp);
                    while (start < end && nums[start] == temp[1]) {
                        start++;
                    }
                    while (start < end && nums[end] == temp[0]) {
                        end--;
                    }
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
                i++;
            }
        }
        return result;
    }
};