class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	vector<vector<int>> result;
    	result.clear();
    	sort(nums.begin(), nums.end());
        while (nums.size() >= 3) {
        	auto pivot = nums.front();
        	auto target = 0 - pivot;
        	auto iter_start = nums.erase(nums.begin());
        	auto iter_end = nums.end();
        	iter_end--;
        	while (iter_start != iter_end) {
        		auto start = *iter_start;
        		auto end = *iter_end;
        		if (start + end == target) {
	        		vector<int> temp;
	        		temp.clear();
	        		temp.push_back(pivot);
	        		temp.push_back(start);
	        		temp.push_back(end);
	        		result.push_back(temp);
        		} else if (start + end < target) {
        			iter_start++;
        		} else {
        			iter_end--;
        		}
        	}
        }
        return result;
    }
};