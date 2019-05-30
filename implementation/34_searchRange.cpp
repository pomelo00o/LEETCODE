class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx = binarySearch(nums, 0, nums.size() - 1, target);
        if (idx == -1) {
            return {-1, -1};
        }
        int start = idx, end = idx;
        while (start > 0 && nums[start - 1] == target) {
            --start;
        }
        while (end < nums.size() - 1 && nums[end + 1] == target) {
            ++end;
        }
        return {start, end};
    }

    int binarySearch(vector<int> &nums, int left, int right, int target) {
        if (left > right) {
            return -1;
        }
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            return binarySearch(nums, mid + 1, right, target);
        } else {
            return binarySearch(nums, left, mid - 1, target);
        }
    }
};