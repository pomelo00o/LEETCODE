class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        int res = 0;
        map<int, vector<int>> m;
        vector<int> vec;
        for (int i = 0; i < values.size(); ++i) {
            m[labels[i]].push_back(values[i]);
        }
        for (map<int, vector<int>>::iterator it = m.begin(); it != m.end(); ++it) {
            sort((*it).second.rbegin(), (*it).second.rend());
            for (int i = 0; i < (*it).second.size() && i < use_limit; ++i) {
                vec.push_back((*it).second[i]);
            }
        }
        sort(vec.rbegin(), vec.rend());
        for (int i = 0; i < num_wanted && i < vec.size(); ++i) {
            res += vec[i];
        }
        return res;
    }
};