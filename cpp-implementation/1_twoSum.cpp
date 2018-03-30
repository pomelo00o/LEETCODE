class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        ans.clear();
        auto first = 0;
        while (true) {
            bool find = false;
            for (auto i = first + 1; i < nums.size(); ++i) {
                if (nums[first] + nums[i] == target) {
                    find = true;
                    ans.push_back(first);
                    ans.push_back(i);
                    return ans;
                }
            }
            if (!find) {
                first++;
            }
        }
    }
};