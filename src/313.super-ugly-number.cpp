/*
 * @lc app=leetcode id=313 lang=cpp
 *
 * [313] Super Ugly Number
 */
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> res(1, 1);
        vector<int> idx(primes.size(), 0);
        while (res.size() < n) {
            int _min_ = INT_MAX;
            vector<int> tmp;
            for (int i = 0; i < primes.size(); ++i) {
                auto e = primes[i] * res[idx[i]];
                tmp.push_back(e);
            }
            for (int i = 0; i < primes.size(); ++i) {
                _min_ = min(_min_, tmp[i]);
            }
            for (int i = 0; i < primes.size(); ++i) {
                if (_min_ == tmp[i]) idx[i] += 1;
            }
            res.push_back(_min_);
        }
        return res.back();
    }
};

