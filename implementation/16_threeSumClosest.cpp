class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2];
        int diff = abs(target - closest);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1; 
            int right = nums.size() - 1;
            while (left < right) {
                int curr = nums[i] + nums[left] + nums[right];
                int diff_new = abs(target - curr);
                if (diff > diff_new) {
                    diff = diff_new;
                    closest = curr;
                }
                if (curr < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return closest;
    }
};