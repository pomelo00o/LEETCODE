class Solution {
public:
    int mySqrt(int x) {
        if(x == 1) {
            return 1;
        }
        int start = 1, end = x/2; 
        while (start <= end) {
            int mid = (start + end)/2;
            if (mid == x / mid) {
                return mid;
            }
            else if (mid < x / mid) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return end;
    }
};