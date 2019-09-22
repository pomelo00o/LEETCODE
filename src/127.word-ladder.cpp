/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<pair<string, int>, int>> q;
        int sz = wordList.size();
        vector<bool> visited(sz, false);
        int endIdx = -1;
        for (int i = 0; i < sz; ++i) {
            if (wordList[i] == endWord) {
                endIdx = i;
                break;
            }
        }
        if (endIdx == -1) return 0;
        q.push(make_pair(make_pair(endWord, endIdx), 1));
        visited[endIdx] = true;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            string str = p.first.first;
            int idx = p.first.second, level = p.second;
            if (isConnected(str, beginWord)) return level + 1;
            for (int i = 0; i < sz; ++i) {
                if (i == idx) continue;
                if (isConnected(str, wordList[i]) && visited[i] == false) {
                    q.push(make_pair(make_pair(wordList[i], i), level + 1));
                    visited[i] = true;
                }
            }
        }
        return 0;
    }

    bool isConnected(string s, string t) {
        int cnt = 0;
        int sz = s.size();
        for (int i = 0; i < sz; ++i) {
            if (s[i] != t[i]) {
                cnt ++;
            }
        }
        return cnt == 1;
    }
};

