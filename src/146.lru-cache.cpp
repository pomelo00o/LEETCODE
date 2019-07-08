/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */
class LRUCache {
private:
    struct KVPair {
        int key;
        int val;
        KVPair(int key, int val): key(key), val(val) {}
    };

    list<KVPair> lru_list;
    unordered_map<int, list<KVPair>::iterator> mp;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        auto iter = mp[key];
        auto res = *iter;
        lru_list.erase(iter);
        lru_list.push_front(res);
        mp[key] = lru_list.begin();
        return res.val;
    }
    
    void put(int key, int value) {
        if (get(key) != -1) {
            (*mp[key]).val = value;
            return;
        }
        KVPair tmp(key, value);
        lru_list.push_front(tmp);
        mp[key] = lru_list.begin();
        while (lru_list.size() > cap) {
            mp.erase(lru_list.back().key);
            lru_list.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

