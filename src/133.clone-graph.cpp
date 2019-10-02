/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& umap) {
        if (!node) return nullptr;
        if (umap.find(node) != umap.end()) return umap[node];
        Node* cloneNode = new Node(node->val);
        umap[node] = cloneNode;
        for (auto n : node->neighbors) {
            cloneNode->neighbors.push_back(dfs(n, umap));
        }
        return cloneNode;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> umap; // unordered_map is used to avoid repeated visit
        return dfs(node, umap);
    }
};
// @lc code=end

