/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */
class NumArray {
private:
    int n_of_bucket;
    vector<int> data, buckets;
public:
    NumArray(vector<int>& nums) {
        data = nums;
        int sz = nums.size();
        n_of_bucket = ceil(sqrt(sz));
        buckets.resize(n_of_bucket);
        for (int i = 0; i < sz; ++i) {
            int bucket_idx = i / n_of_bucket;
            buckets[bucket_idx] += data[i];
        }
    }
    
    void update(int i, int val) {
        int idx = i / n_of_bucket;
        buckets[idx] += val - data[i];
        data[i] = val;
    }
    
    int sumRange(int i, int j) {
        int cnt = 0;
        int start = i / n_of_bucket, end = j / n_of_bucket;
        if (start == end) {
            for (int k = i; k <= j; ++k) {
                cnt += data[k];
            }
            return cnt;
        }
        for (int k = i; k < (start + 1) * n_of_bucket; ++k) {
            cnt += data[k];
        }
        for (int k = start + 1; k < end; ++k) {
            cnt += buckets[k];
        }
        for (int k = end * n_of_bucket; k <= j; ++k) {
            cnt += data[k];
        }
        return cnt;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

