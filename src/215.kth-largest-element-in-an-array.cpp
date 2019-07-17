/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            if (pos < k - 1) {
                left = pos + 1;
            } else {
                right = pos - 1;
            }
        }
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l], nums[r]);
                l += 1;
                r -= 1;
            }
            if (nums[l] >= pivot) l += 1;
            if (nums[r] <= pivot) r -= 1; 
        }
        swap(nums[left], nums[r]);
        return r;
    }
};

