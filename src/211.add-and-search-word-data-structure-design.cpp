/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Add and Search Word - Data structure design
 */
class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode() {
        isEnd = false;
        for (auto &e : children) {
            e = nullptr;
        }
    }
};

class WordDictionary {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* p = root;
        for (auto &c : word) {
            int key = c - 'a';
            if (!p->children[key]) {
                p->children[key] = new TrieNode();
            }
            p = p->children[key];
        }
        p->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return helper(root, word, 0);
    }

    bool helper(TrieNode* p, string word, int idx) {
        if (idx == word.size()) return p->isEnd;
        char c = word[idx];
        if (c == '.') {
            for (auto &a : p->children) {
                if (a && helper(a, word, idx + 1)) return true;
            }
            return false;
        } else {
            return p->children[c - 'a'] && helper(p->children[c - 'a'], word, idx + 1);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

