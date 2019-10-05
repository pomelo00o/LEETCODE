/*
 * @lc app=leetcode id=865 lang=cpp
 *
 * [865] Smallest Subtree with all the Deepest Nodes
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
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }

    pair<TreeNode*, int> dfs(TreeNode* node) {
        if (!node) return {nullptr, 0};
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        if (left.second > right.second) {
            return {left.first, left.second + 1};
        } else if (left.second < right.second) {
            return {right.first, right.second + 1};
        }
        return {node, left.second + 1};
    }
};
// @lc code=end

