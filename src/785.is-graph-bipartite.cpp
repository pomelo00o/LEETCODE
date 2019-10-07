/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
class Solution {
private:
    bool isValid(vector<vector<int>>& graph, int color, int idx, vector<int>& colors) {
        if (colors[idx] != 0) {
            return colors[idx] == color;
        }
        colors[idx] = color;
        for (int neighbor : graph[idx]) {
            if (!isValid(graph, color * (-1), neighbor, colors)) {
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size(), 0);
        for (int i = 0; i < graph.size(); ++i) {
            if (colors[i] == 0 && !isValid(graph, 1, i, colors)) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

