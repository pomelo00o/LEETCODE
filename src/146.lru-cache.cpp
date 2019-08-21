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
        KVPair(int k, int v): key(k), val(v) {};
    };
    int cap;
    list<KVPair> lru_list;
    unordered_map<int, list<KVPair>::iterator> umap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (umap.find(key) == umap.end()) return -1;
        list<KVPair>::iterator iter = umap[key];
        KVPair kv = *iter;
        lru_list.erase(iter);
        lru_list.push_front(kv);
        umap[key] = lru_list.begin();
        return kv.val;
    }
    
    void put(int key, int value) {
        if (get(key) != -1) {
            (*umap[key]).val = value;
            return;
        }
        KVPair kv(key, value);
        lru_list.push_front(kv);
        umap[key] = lru_list.begin();
        while (lru_list.size() > cap) {
            int k = lru_list.back().key;
            umap.erase(k);
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

