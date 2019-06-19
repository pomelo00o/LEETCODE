class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> ordered(nums);
        sort(ordered.begin(), ordered.end());
        auto size = nums.size();
        auto start = 0;
        auto end = size - 1;
        while (start < size && nums[start] == ordered[start]) {
            start++;
        }
        while (end > start && nums[end] == ordered[end]) {
            end--;
        }
        return end + 1 - start;
    }
};