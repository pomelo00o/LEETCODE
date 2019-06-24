/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
using namespace std;
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = 0, right = mountainArr.length() - 1;
        while (peak < right) {
            int mid = (peak + right) / 2;
            if (mountainArr.get(mid) > mountainArr.get(mid + 1)) right = mid;
            else peak = mid + 1;
        }
        int idx = binary_search(target, mountainArr, peak, right, false);
        return idx != -1 ? idx : binary_search(target, mountainArr, 0, peak - 1, true);
    }
    int binary_search(int target, MountainArray &mountainArr, int left, int right, bool asc) {
        if (mountainArr.get(left) > target || mountainArr.get(right) < target) return -1;
        int mid = (left + right) / 2;
        if (mountainArr.get(mid) == target) return mid;
        if (mountainArr.get(mid) < target) left = mid + 1;
        else right = mid - 1;
        return binary_search(target, mountainArr, left, right);
    }
};