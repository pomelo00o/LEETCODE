/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited{{0}};
        queue<int> q{{0}};
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            auto vec = rooms[t];
            for (auto v : vec) {
                if (visited.count(v)) continue;
                else visited.insert(v);
                if (visited.size() == rooms.size()) return true;
                q.push(v);
            }
        }
        return visited.size() == rooms.size();
    }
};

