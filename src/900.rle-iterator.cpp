/*
 * @lc app=leetcode id=900 lang=cpp
 *
 * [900] RLE Iterator
 */

// @lc code=start
using namespace std;
class RLEIterator {
private:
    vector<int> nums = {};
    vector<int> idx = {};
    int totalNext = 0;
    int currIdx = 0;
public:
    RLEIterator(vector<int>& A) {
        for (int i = 0; i < A.size(); ++i) {
            if (i % 2 == 0) {
                if (A[i] == 0) continue;
                idx.push_back(A[i]);
                nums.push_back(A[i + 1]);
            }
        }
        for (auto e : idx) {
            cout << e << endl;
        }
    }
    
    int next(int n) {
        int stepLeft = idx[currIdx] - totalNext;
        if (n <= stepLeft) {
            totalNext += n;
        } else {
            totalNext = totalNext + n - idx[currIdx];
            currIdx += 1;
        }
        if (currIdx >= idx.size()) return -1;
        return nums[currIdx];
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
// @lc code=end

