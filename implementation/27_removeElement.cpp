class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto iter = nums.begin();
        while (iter != nums.end()) {
        	if ((*iter) == val) {
        		nums.erase(iter);
        	} else {
        		iter++;
        	}
        }
        return nums.size();
    }
};