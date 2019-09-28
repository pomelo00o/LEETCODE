class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, int> indegree;
        unordered_map<char, unordered_set<char>> graph;

        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                char c = words[i][j];
                indegree[c] = 0;
            }
        }

        for (int i = 0; i < words.size() -1; ++i) {
            string curr = words[i], next = words[i + 1];
            int len = min(curr.size(), next.size());
            for (int j = 0; j < len; ++j) {
                if (curr[j] != next[j]) {
                    unordered_set<char> s = graph[curr[j]];
                    if (s.find(next[j]) == s.end()) { // does not contain next[j]
                        graph[curr[j]].insert(next[j]);
                        indegree[next[j]] ++;
                    }
                    break;
                }
            }
        }

        queue<char> q;
        string res;

        for (auto e : indegree) {
            if (e.second == 0) {
                q.push(e.first);
            }
        }

        while (!q.empty()) {
            char c = q.front();
            q.pop();
            res += c;
            if (!graph[c].empty()) {
                for (auto &e : graph[c]) {
                    indegree[e] --;
                    if (indegree[e] == 0) q.push(e);
                }
            }
        }

        return res.size() == indegree.size() ? res : "";
    }
};