/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void updateParent(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!node) return;
        if (node->left) {
            parent[node->left] = node;
        }
        if (node->right) {
            parent[node->right] = node;
        }
        updateParent(node->left, parent);
        updateParent(node->right, parent);
    }

    void helper(TreeNode* node, int K, unordered_map<TreeNode*, TreeNode*>& parent, unordered_set<TreeNode*> visited, vector<int>& res) {
        if (visited.find(node) != visited.end()) return;
        visited.insert(node);   
        if (K == 0) {
            res.push_back(node->val);
            return;
        }
        if (node->left) {
            helper(node->left, K - 1, parent, visited, res);
        }
        if (node->right) {
            helper(node->right, K - 1, parent, visited, res);
        }
        if (parent.find(node) != parent.end()) {
            helper(parent[node], K - 1, parent, visited, res);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (!root) return {};
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_set<TreeNode*> visited;
        vector<int> res;
        updateParent(root, parent);
        helper(target, K, parent, visited, res);
        return res;
    }
};
// @lc code=end

