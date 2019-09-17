/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int pivot = bsearch(nums, target, 0, nums.size() - 1);
        if (pivot == -1) return {-1, -1};
        int s = pivot, e = pivot;
        while (s > 0 && nums[s] == nums[s - 1]) s -= 1;
        while (e < nums.size() - 1 && nums[e] == nums[e + 1]) e += 1;
        return {s, e};
    }

    int bsearch(vector<int>& nums, int target, int s, int e) {
        if (s > e) return -1;
        int mid = s + (e - s) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            s = mid + 1;
            return bsearch(nums, target, s, e);
        } else {
            e = mid - 1;
            return bsearch(nums, target, s, e);
        }
    }
};

