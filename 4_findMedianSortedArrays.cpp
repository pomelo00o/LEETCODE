class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        v.clear();
        auto len1 = nums1.size();
        auto len2 = nums2.size();
        for (auto i = 0; i < len1; ++i) {
        	v.push_back(nums1[i]);
        }
        for (auto i = 0; i < len2; ++i) {
        	v.push_back(nums2[i]);
        }
        std::sort(v.begin(), v.end());
        auto len_target = v.size();

        if (len_target == 0) {
        	return 0;
        } else if (len_target == 1) {
        	return v[0];
        } else {
        	if (len_target % 2 == 0) {
        		return (double(v[len_target / 2 - 1]) + double(v[len_target / 2])) / 2;
        	} else {
        		return v[(len_target - 1) / 2];
        	}
        }
    }
};