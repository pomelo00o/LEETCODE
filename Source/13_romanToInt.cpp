class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            int curr = m[s[i]];
            if (i == s.size() - 1) {
                res += curr;
                break;
            }
            int next = m[s[i+1]];
            curr = curr >= next ? curr : -curr;
            res += curr;
        }
        return res;
    }
};