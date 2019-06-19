class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }

    void merge_sort(vector<int>& nums, int l, int r) {
        if (r <= l) return;
        int m = l + (r - l) / 2;
        merge_sort(nums, l, m);
        merge_sort(nums, m + 1, r);
        int left = l;
        int right = m + 1;
        int i = 0;
        vector<int> res(r - l + 1, 0);
        while (left <= m || right <= r) {
            int v1 = left <= m ? nums[left] : INT_MAX;
            int v2 = right <= r ? nums[right] : INT_MAX;
            res[i] = v1 < v2 ? nums[left++] : nums[right++];
            i++;
        }
        for (int i = l; i <= r; ++i) {
            nums[i] = res[i - l];
        }
    }
};