/*
 * @lc app=leetcode id=475 lang=cpp
 *
 * [475] Heaters
 */

/*
 * 二分查找找到比当前house大的第一个heater，比较abs(heaters[right] - h)和abs(heaters[right - 1] - h)
 * 更新res = max(res, min(d1, d2))
 * 需要注意下标越界问题
 */


class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int res = 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        for (int h : houses) {
            int left = 0, right = heaters.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (heaters[mid] < h) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            int d1 = (right == heaters.size()) ? INT_MAX : abs(heaters[right] - h);
            int d2 = (right == 0) ? INT_MAX : abs(heaters[right - 1] - h);
            res = max(res, min(d1, d2));
        }
        return res;
    }
};

