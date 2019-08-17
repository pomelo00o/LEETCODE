/*
 * @lc app=leetcode id=1146 lang=cpp
 *
 * [1146] Snapshot Array
 */
class SnapshotArray {
private:
    vector<map<int, int>> arr; 
    /* arr[0]: {
     * 0: 5,
     * 1: 15, 
     * ...
     * }
     */

    int snap_cnt = 0;

public:
    SnapshotArray(int length) {
        arr.resize(length);
    }
    
    void set(int index, int val) {
        arr[index][snap_cnt] = val;
    }
    
    int snap() {
        return snap_cnt++;
    }
    
    int get(int index, int snap_id) {
        while (snap_id >= 0) {
            int val = arr[index][snap_id];
            if (val > 0) return val;
            snap_id -= 1;
        }
        return 0;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

