class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int stop[1000] = {};
        for (auto t : trips) {
            stop[t[1]] += t[0];
            stop[t[2]] -= t[0];
        }
        for (int i = 0; i < 1000; ++i) {
            capacity -= stop[i];
            if (capacity < 0) {
                return false;
            }
        }
        return true;
    }
};