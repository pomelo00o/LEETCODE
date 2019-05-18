class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res;
        res.clear();
        // construct a hashMap <number->index>
        for (auto i = 0; i < nums.size(); ++i) {
            m[nums[i]] = i;
        }

        for (auto i = 0; i < nums.size(); ++i) {
            auto t = target - nums[i];
            if (m.count(t) && m[t] != i) { // unordered_map.count function counts the number of appearance
                res.push_back(i);
                res.push_back(m[t]);
                break;
            }
        }

        return res;
    }
};
