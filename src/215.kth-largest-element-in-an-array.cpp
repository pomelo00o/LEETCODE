/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */
class Solution {
private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l], nums[r]);
                l ++;
                r --;
            }
            if (nums[l] >= pivot) {
                l ++;
            }
            if (nums[r] <= pivot) {
                r --;
            }
        }
        swap(nums[left], nums[r]);
        return r;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int p = partition(nums, left, right);
            if (p == k - 1) return nums[p];
            if (p < k - 1) {
                left = p + 1;
            } else {
                right = p - 1;
            }
        }
        return -1;
    }
};

