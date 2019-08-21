/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */
class MyHashMap {
private:
    vector<vector<int>> vec;
    // hashKey: which segment it falls into
    // bucketKey: within each segment, which bucket it falls into
    int hashKey;
    int bucketKey;

public:
    /** Initialize your data structure here. */
    MyHashMap() {
        vec.resize(1000, vector<int>(1000, -1));
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        hashKey = key % 1000;
        bucketKey = key / 1000;
        vec[hashKey][bucketKey] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        hashKey = key % 1000;
        bucketKey = key / 1000;
        return vec[hashKey][bucketKey];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        hashKey = key % 1000;
        bucketKey = key / 1000;
        vec[hashKey][bucketKey] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

