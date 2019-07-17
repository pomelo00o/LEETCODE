/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int left = 0, right = points.size() - 1;
        while (true) {
            int pos = partition(points, left, right);
            if (pos == K - 1) break;
            if (pos > K - 1) {
                right = pos - 1;
            } else {
                left = pos + 1;
            }
        }
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }

    int partition(vector<vector<int>>& points, int left, int right) {
        int pivot = pow(points[left][0], 2) + pow(points[left][1], 2);
        int l = left + 1, r = right;
        while (l <= r) {
            auto lp = pow(points[l][0], 2) + pow(points[l][1], 2);
            auto rp = pow(points[r][0], 2) + pow(points[r][1], 2);
            if (lp > pivot && rp < pivot) {
                swap(points[l], points[r]);
                l += 1, r -= 1;
            }
            if (lp <= pivot) l += 1;
            if (rp >= pivot) r -= 1;
        }
        swap(points[left], points[r]);
        return r;
    }
};

