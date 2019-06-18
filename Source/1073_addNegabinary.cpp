class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        res.clear();
        int m = arr1.size() - 1, n = arr2.size() - 1, carry = 0;
        while (m >= 0 || n >= 0 || carry) {
            if (m >= 0) carry += arr1[m--];
            if (n >= 0) carry += arr2[n--];
            res.push_back(carry & 1);
            carry = -(carry >> 1);
        }
        while (res.size() > 1 && res.back() == 0) {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};